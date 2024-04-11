fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val (d, k) = readLine()!!.split(" ").map { it.toLong() }
        var z = 0L
        while (2L * z * z * k * k <= d * d) {
            z++
        }
        println(if (k * k * ((z * z) + ((z - 1L) * (z - 1L))) > d * d) "Utkarsh" else "Ashish")
    }
}