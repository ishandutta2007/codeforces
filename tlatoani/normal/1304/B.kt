import java.util.*

fun main() {
    val line = readLine()!!
    val six = line.indexOf(' ')
    val n = line.substring(0, six).toInt()
    val m = line.substring(six + 1).toInt()
    val strings = TreeSet<String>()
    var prefix = ""
    var suffix = ""
    var middle = ""
    for (j in 1..n) {
        strings.add(readLine()!!)
    }
    while (!strings.isEmpty()) {
        val s = strings.first()
        strings.remove(s)
        val r = s.reversed()
        if (strings.remove(r)) {
            prefix += s
            suffix = r + suffix
        } else {
            if (s == r && s.length > middle.length) {
                middle = s
            }
        }
    }
    val answer = prefix + middle + suffix
    println(answer.length)
    println(answer)
}