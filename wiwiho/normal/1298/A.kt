fun main() {
    readLine()?.split(" ")?.map {it.toInt()}!!.toMutableList().sorted().let { println("${it[3] - it[0]} ${it[3] - it[1]} ${it[3] - it[2]}") }
}