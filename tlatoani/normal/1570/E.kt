fun main() {
    repeat(readLine()!!.toInt()) {
        val s = readLine()!!
        val answer = String(s.map { if (it == '0') ' ' else '1' }.toCharArray()).trim().count { it == ' ' }
        println(answer)
    }
}