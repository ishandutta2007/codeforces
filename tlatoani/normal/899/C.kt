fun main() {
    val n = readLine()!!.toInt()
    println(if (n % 4 == 0 || n % 4 == 3) 0 else 1)
    val answer = mutableListOf<Int>()
    var j = 2 + (n % 2)
    while (j <= n) {
        if ((j / 2) % 2 == 1) {
            answer.add(j)
        } else {
            answer.add(j - 1)
        }
        j += 2
    }
    print(answer.size)
    print(' ')
    println(answer.joinToString(" "))
}