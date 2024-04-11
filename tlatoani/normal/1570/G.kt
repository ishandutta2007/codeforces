fun main() {
    println("? " + (0..99).joinToString(" "))
    val x = readLine()!!.toInt()
    println("? " + (1..100).map { it shl 7 }.joinToString(" "))
    val y = readLine()!!.toInt()
    val answer = ((x shr 7) shl 7) + (y and 127)
    println("! $answer")
}