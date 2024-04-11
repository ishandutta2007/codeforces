import java.util.*

fun main() {
    val n = readLine()!!.toInt()
    val tokenizer = StringTokenizer(readLine()!!)
    val array = IntArray(n) { tokenizer.nextToken().toInt() }
    val distinct = mutableSetOf<Int>()
    val changes = LinkedList<Int>()
    if (0 in array) {
        distinct.add(0)
    }
    for (j in array.reversed()) {
        changes.addFirst(j)
        var mask = 0
        changes.loop { k ->
            if (mask or k != mask) {
                mask = mask or k
                distinct.add(mask)
                true
            } else {
                false
            }
        }
    }
    println(distinct.size)
}

fun <E> LinkedList<E>.loop(keep: (E) -> Boolean) {
    val iterator = iterator()
    while (iterator.hasNext()) {
        if (!keep(iterator.next())) {
            iterator.remove()
        }
    }
}