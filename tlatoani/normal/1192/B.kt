import java.util.*
import kotlin.math.max

fun main() {
    val jin = Scanner(System.`in`)
    val n = jin.nextInt()
    val q = jin.nextInt()
    val w = jin.nextLong()
    val nodes = Array(n + 1, ::Node)
    nodes[1].parent = nodes[0]
    nodes[1].edges.add(Edge(nodes[0], 0, 0))
    for (i in 0 until n - 1) {
        val a = jin.nextInt()
        val b = jin.nextInt()
        val length = jin.nextLong()
        nodes[a].edges.add(Edge(nodes[b], length, i))
        nodes[b].edges.add(Edge(nodes[a], length, i))
    }
    val dfs = Array(n) { nodes[1] }
    val qodes = Array(n - 1) { nodes[0] }
    var j = 1
    for (i in 0 until n) {
        for (k in 0 until dfs[i].edges.size - 1) {
            var edge = dfs[i].edges[k]
            if (edge.node == dfs[i].parent) {
                edge = dfs[i].edges.last()
                dfs[i].edges[k] = edge
            }
            qodes[edge.ix] = edge.node
            edge.node.parent = dfs[i]
            edge.node.parentLength = edge.length
            dfs[j] = edge.node
            j++
        }
        dfs[i].edges.removeAt(dfs[i].edges.size - 1)
    }
    for (node in dfs.reversed()) {
        node.parent.subTreeSize += node.subTreeSize
        var bestIx = -1
        for (k in 0 until node.edges.size) {
            node.edges[k].node.treeix = k
            if (node.bestChild == null || node.bestChild!!.subTreeSize < node.edges[k].node.subTreeSize) {
                node.bestChild = node.edges[k].node
                bestIx = k
            }
        }
        //println("$node.bestChild = ${node.bestChild}")
        if (node.bestChild != null) {
            node.edges.last().node.treeix = bestIx
            node.edges[bestIx] = node.edges.last()
            node.edges.removeAt(node.edges.size - 1)
        }
        node.hortree = Hortree(node.edges.size)
    }
    for (node in dfs) {
        if (node.parent.bestChild == node) {
            continue
        }
        var amt = 0
        var subNode: Node? = node.bestChild
        while (subNode != null) {
            subNode.treeix = amt
            subNode = subNode.bestChild
            amt++
        }
        node.vertree = Vertree(node, amt)
        subNode = node.bestChild
        while (subNode != null) {
            subNode.vertree = node.vertree
            subNode = subNode.bestChild
        }
    }
    for (node in dfs.reversed()) {
        if (node != nodes[1]) {
            node.update()
        }
    }
    var last: Long = 0
    for (i in 1..q) {
        val d = (jin.nextLong() + last) % (n - 1)
        var e = (jin.nextLong() + last) % w
        var node = qodes[d.toInt()]
        //println("node = $node, e = $e")
        node.parentLength = e
        while (node != nodes[1]) {
            node.update()
            if (node == node.parent.bestChild) {
                node = node.vertree.topNode
            } else {
                node = node.parent
            }
        }
        last = maxOf(nodes[1].hortree.posAnswer(), nodes[1].vertree.posAnswer(), nodes[1].hortree.longest() + nodes[1].vertree.longest())
        println(last)
    }
}

class Node(val ix: Int) {
    lateinit var parent: Node
    var parentLength: Long = -1
    var subTreeSize = 1
    val edges = mutableListOf<Edge>()
    var bestChild: Node? = null
    lateinit var hortree: Hortree
    lateinit var vertree: Vertree
    var treeix = -1

    fun update() {
        //println("$this.update()")
        if (parent.bestChild == this) {
            vertree.update(
                    treeix,
                    Verval(
                            parentLength,
                            hortree.longest() + parentLength,
                            hortree.longest(),
                            hortree.posAnswer()
                    )
            )
        } else {
            parent.hortree.update(
                    treeix,
                    Horval(
                            max(vertree.longest(),
                                    hortree.longest()) + parentLength,
                            0,
                            maxOf(vertree.posAnswer(), hortree.posAnswer(), vertree.longest() + hortree.longest())
                    )
            )
        }
    }

    override fun toString() = "nodes[$ix]"
}

class Edge(val node: Node, val length: Long, val ix: Int)

val HORIZONTAL_IDENTITY = Horval(0, 0, 0)
val VERTICAL_IDENTITY = Verval(0, 0, 0, 0)

data class Horval(val longest1: Long, val longest2: Long, val posAnswer: Long) {
    operator fun plus(other: Horval): Horval {
        if (longest1 > other.longest1) {
            return Horval(longest1, max(longest2, other.longest1), max(posAnswer, other.posAnswer))
        } else {
            return Horval(other.longest1, max(longest1, other.longest2), max(posAnswer, other.posAnswer))
        }
    }
}

data class Verval(val length: Long, val longest: Long, val longestToUse: Long, val posAnswer: Long) {
    // this is above, other is below
    operator fun times(other: Verval) = Verval(
            length + other.length,
            max(longest, other.longest + length),
            max(longestToUse + other.length, other.longestToUse),
            maxOf(posAnswer, other.posAnswer, longestToUse + other.longest)
    )
}

class Hortree(amt: Int) {
    val length: Int
    val array: Array<Horval>

    init {
        var l = 1
        while (l < amt) {
            l *= 2
        }
        length = l
        array = Array(length * 2) { HORIZONTAL_IDENTITY }
    }

    fun update(index: Int, newVal: Horval) {
        var node = index + length
        array[node] = newVal
        node = node shr 1
        while (node > 0) {
            array[node] = array[2 * node] + array[(2 * node) + 1]
            node = node shr 1
        }
    }

    fun longest() = array[1].longest1
    fun posAnswer() = max(array[1].longest1 + array[1].longest2, array[1].posAnswer)
}

class Vertree(val topNode: Node, amt: Int) {
    val length: Int
    val array: Array<Verval>

    init {
        var l = 1
        while (l < amt) {
            l *= 2
        }
        length = l
        array = Array(length * 2) { VERTICAL_IDENTITY }
    }

    fun update(index: Int, newVal: Verval) {
        //println("update($index, $newVal)")
        var node = index + length
        array[node] = newVal
        //println("array[$node] = ${array[node]}")
        node = node shr 1
        while (node > 0) {
            array[node] = array[2 * node] * array[(2 * node) + 1]
            //println("array[$node] = ${array[node]}")
            node = node shr 1
        }
    }

    fun longest() = array[1].longest
    fun posAnswer() = max(array[1].longestToUse, array[1].posAnswer)
}