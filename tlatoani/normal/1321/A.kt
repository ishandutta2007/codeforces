fun main() {
    val n = readLine()!!.toInt()
    val red = readLine()!!
    val blue = readLine()!!
    var rojo = 0
    var azul = 0
    for (j in 0 until n) {
        if (red[2 * j] == '1' && blue[2 * j] == '0') {
            rojo++
        } else if (red[2 * j] == '0' && blue[2 * j] == '1') {
            azul++
        }
    }
    when {
        rojo > azul -> println(1)
        rojo == 0 -> println(-1)
        else -> println(1 + (azul / rojo))
    }
}