import java.lang.StringBuilder
import java.util.*

const val CHARAS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"

fun main() {
    val jin = Scanner(System.`in`)
    val builder = StringBuilder()
    for (c in 1..jin.nextInt()) {
        val r = jin.nextInt()
        val c = jin.nextInt()
        val k = jin.nextInt()
        val grid = Array(r) { jin.next() }
        var rice = 0
        for (row in grid) {
            for (chara in row) {
                if (chara == 'R') {
                    rice++
                }
            }
        }
        var chicken = 0
        var currRice = 0
        val answer = Array(r) { CharArray(c) }
        for (y in 0 until r) {
            for (x in if (y % 2 == 0) 0 until c else c - 1 downTo 0) {
                if (grid[y][x] == 'R') {
                    currRice++
                }
                if (currRice > (rice / k) + if (chicken < rice % k) 1 else 0) {
                    chicken++
                    currRice = 1
                }
                //println("($y, $x) -> chicken = $chicken, currRice = $currRice")
                answer[y][x] = CHARAS[chicken]
            }
        }
        for (row in answer) {
            builder.append(row)
            builder.append('\n')
        }
    }
    print(builder)
}