import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val a = Array(n) { jin.readLine().map { it - '0' }.toIntArray() }
        jin.readLine()
        val b = Array(n) { jin.readLine().map { it - '0' }.toIntArray() }
        normalize(n, a)
        normalize(n, b)
        out.appendln(if ((0 until n).all { y -> (0 until n).all { x -> a[y][x] == b[y][x] } }) "yEs" else "nO")
    }
    print(out)
}

fun normalize(n: Int, matrix: Array<IntArray>) {
    for (y in 1 until n) {
        for (x in 1 until n) {
            matrix[y][x] = matrix[0][0] xor matrix[y][0] xor matrix[0][x] xor matrix[y][x]
        }
    }
    for (y in 0 until n) {
        matrix[y][0] = 0
    }
    for (x in 0 until n) {
        matrix[0][x] = 0
    }
}