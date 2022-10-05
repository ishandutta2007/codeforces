import java.util.*

fun main() {
    val jin = Scanner(System.`in`)
    val treeSet = TreeSet<Problem>()
    for (i in 1..jin.nextInt()) {
        treeSet.add(Problem(i, jin.nextInt()))
    }
    if (treeSet.size < 3) {
        println("-1 -1 -1")
    } else {
        print(treeSet.first().ix)
        treeSet.remove(treeSet.first())
        print(" ")
        print(treeSet.first().ix)
        print(" ")
        println(treeSet.last().ix)
    }
}

data class Problem(val ix: Int, val complexity: Int): Comparable<Problem> {
    override fun compareTo(other: Problem) = complexity - other.complexity
}