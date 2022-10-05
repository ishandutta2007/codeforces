fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        readLine()
        println(3 * n)
        for (j in 1..n step 2) {
            val k = j + 1
            repeat(2) {
                println("1 $j $k")
                println("2 $j $k")
                println("1 $j $k")
            }
        }
    }
}