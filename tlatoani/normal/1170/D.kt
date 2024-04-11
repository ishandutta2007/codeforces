import java.util.*

fun main() {
    val jin = Scanner(System.`in`)
    val lists = LinkedList<MutableList<Int>>()
    val m = jin.nextInt()
    val input = IntArray(m) { jin.nextInt() }
    for (c in input.reversed()) {
        if (c == -1) {
            lists.add(mutableListOf())
        } else {
            val list = lists.removeFirst()
            list.add(c)
            lists.addLast(list)
        }
    }
    println(lists.size)
    println(lists.reversed().joinToString("\n", "", "")
        { list -> list.reversed().joinToString(" ", "${list.size} ", "") })
}