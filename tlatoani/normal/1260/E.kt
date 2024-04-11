import java.util.*

fun main() {
    val jin = Scanner(System.`in`)
    var n = jin.nextInt()
    val dollars = LongArray(n) { jin.nextLong() }
    var friend = 0
    while (dollars[friend] >= 0) {
        dollars[friend] = 0
        friend++
    }
    dollars[friend] = 0
    val boxers = TreeSet<Int> { a, b ->
        if (dollars[a] != dollars[b]) {
            dollars[a].compareTo(dollars[b])
        } else {
            b - a
        }
    }
    var answer = dollars.last()
    var j = n - 2
    while (n > 1) {
        n /= 2
        val lim = j - n
        while (j > lim) {
            boxers.add(j)
            j--
        }
        val boxer = boxers.first()
        boxers.remove(boxer)
        answer += dollars[boxer]
    }
    println(answer)
}

data class Boxer(val strength: Int, val dollars: Long): Comparable<Boxer> {
    override fun compareTo(other: Boxer) = compareValuesBy(this, other, { it.dollars }, { it.strength})
}