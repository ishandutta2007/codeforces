import java.util.*

fun main() {
    readLine()
    val listo = LinkedList(readLine()!!.toList())
    val original = listo.size
    for (chara in 'z' downTo 'b') {
        val iterator = listo.listIterator()
        while (iterator.hasNext()) {
            //println(listo)
            if (iterator.next() == chara) {
                iterator.previous()
                if (iterator.hasPrevious()) {
                    if (iterator.previous() == chara - 1) {
                        iterator.next()
                        iterator.next()
                        iterator.remove()
                        continue
                    }
                    iterator.next()
                    iterator.next()
                } else {
                    iterator.next()
                }
                if (iterator.hasNext()) {
                    if (iterator.next() == chara - 1) {
                        iterator.previous()
                        iterator.previous()
                        iterator.remove()
                        if (iterator.hasPrevious()) {
                            iterator.previous()
                        }
                        continue
                    }
                    iterator.previous()
                }
            }
        }
    }
    println(original - listo.size)
}