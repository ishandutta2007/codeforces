import java.util.*

fun main() {
    val jin = Scanner(System.`in`)
    val n = jin.nextInt()
    val m = jin.nextInt()
    val maze = arrayOf("#".repeat(m + 2)) + Array(n) { "#" + jin.next() + "#" } + arrayOf("#".repeat(m + 2))
    var rx = 0
    var ry = 0
    for (y in 1..n) {
        for (x in 1..m) {
            if (maze[y][x] == 'S') {
                ry = y
                rx = x
            }
        }
    }
    val instrucciones = jin.next().map { it - '0' }
    var answer = 0
    for (mask in 0 until 256) {
        val mapping = IntArray(4) { (mask shr (2 * it)) and 3 }
        var works = true
        for (j in 0 until 4) {
            for (k in 0 until j) {
                if (mapping[j] == mapping[k]) {
                    works = false
                }
            }
        }
        if (!works) {
            continue
        }
        //println("mapping ${mapping.contentToString()}")
        var y = ry
        var x = rx
        for (instru in instrucciones) {
            when (mapping[instru]) {
                0 -> y++
                1 -> x++
                2 -> y--
                3 -> x--
            }
            if (maze[y][x] == 'E') {
                break
            }
            if (maze[y][x] == '#') {
                works = false
                break
            }
        }
        if (maze[y][x] == 'E') {
            //println("mapping ${mapping.contentToString()} works")
            answer++
        }
    }
    println(answer)
}