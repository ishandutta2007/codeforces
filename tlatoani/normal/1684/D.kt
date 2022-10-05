fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, k) = readLine()!!.split(" ").map { it.toInt() }
        val traps = readLine()!!.split(" ").map { it.toLong() }
        var answer = traps.sum()
        val mejoras = traps.withIndex().map { (j, x) -> (n - j).toLong() - x }
        answer += mejoras.sorted().subList(0, k).sum()
        val kl = k.toLong()
        answer -= (kl * (kl + 1L)) / 2L
        println(answer)
    }
}