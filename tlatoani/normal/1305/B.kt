fun main() {
    val s = " " + readLine()!!
    var j1 = 1
    var j2 = s.length - 1
    val left = mutableListOf<Int>()
    val right = mutableListOf<Int>()
    while (j1 < j2) {
        while (j1 < j2 && s[j1] != '(') {
            j1++
        }
        while (j2 > j1 && s[j2] != ')') {
            j2--
        }
        if (j1 == j2) {
            break
        }
        left.add(j1)
        right.add(j2)
        j1++
        j2--
    }
    val answer = left + right.reversed()
    if (answer.isEmpty()) {
        println(0)
    } else {
        println(1)
        println(answer.size)
        println(answer.joinToString(" "))
    }
}