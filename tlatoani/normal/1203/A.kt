import java.util.*

fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val tokenizer = StringTokenizer(readLine()!!)
        val linkedList = LinkedList<Int>()
        for (j in 1..n) {
            linkedList.add(tokenizer.nextToken().toInt())
        }
        while (linkedList[0] != 1) {
            linkedList.add(linkedList.removeFirst())
        }
        if ((1..n).all { linkedList[it - 1] == it }) {
            println("YES")
        } else {
            while (linkedList[0] != n) {
                linkedList.add(linkedList.removeFirst())
            }
            if ((1..n).all { linkedList[n - it] == it }) {
                println("YES")
            } else {
                println("NO")
            }
        }
    }
}