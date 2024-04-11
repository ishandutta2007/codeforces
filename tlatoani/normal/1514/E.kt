import java.util.*

fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        fun query1(a: Int, b: Int): Boolean {
            println("1 $a $b")
            return readLine() == "1"
        }
        fun query2(a: Int, bs: List<Int>): Boolean {
            println("2 $a ${bs.size} ${bs.joinToString(" ")}")
            return readLine() == "1"
        }
        fun sort(nodes: List<Int>): List<Int> {
            if (nodes.size == 1) {
                return nodes
            } else {
                val left = sort(nodes.subList(0, nodes.size / 2))
                val right = sort(nodes.subList(nodes.size / 2, nodes.size))
                val res = mutableListOf<Int>()
                var j = 0
                var k = 0
                while (j < left.size && k < right.size) {
                    if (query1(left[j], right[k])) {
                        res.add(left[j])
                        j++
                    } else {
                        res.add(right[k])
                        k++
                    }
                }
                while (j < left.size) {
                    res.add(left[j])
                    j++
                }
                while (k < right.size) {
                    res.add(right[k])
                    k++
                }
                return res
            }
        }
        val sorted = sort((0 until n).toList())
        val stack = Stack<List<Int>>()
        for (a in sorted) {
            val component = mutableListOf(a)
            while (stack.isNotEmpty()) {
                val queried = mutableListOf<Int>()
                for (other in stack) {
                    queried.addAll(other)
                }
                if (query2(a, queried)) {
                    component.addAll(stack.pop())
                } else {
                    break
                }
            }
            stack.push(component)
        }
        val position = IntArray(n)
        for ((j, component) in stack.withIndex()) {
            for (a in component) {
                position[a] = j
            }
        }
        println(3)
        for (a in 0 until n) {
            println(CharArray(n) { b -> if (position[a] <= position[b]) '1' else '0' })
        }
        if (readLine() == "-1" ) {
            return
        }
    }
}