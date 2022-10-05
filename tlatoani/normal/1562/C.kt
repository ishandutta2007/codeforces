fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val s = " " + readLine()!!
        val k = ((n / 2) + 1..n).find { s[it] == '0' }
        if (k == null) {
            if (s[n / 2] == '0') {
                println("${n / 2} $n ${(n / 2) + 1} $n")
            } else {
                println("${n / 2} ${n - 1} ${(n / 2) + 1} $n")
            }
        } else {
            println("1 $k 1 ${k - 1}")
        }
    }
}