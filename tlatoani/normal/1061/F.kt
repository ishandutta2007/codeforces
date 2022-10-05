import java.util.Scanner
import kotlin.random.Random

fun main() {
    val jin = Scanner(System.`in`)
    val n = jin.nextInt()
    val k = jin.nextInt()
    var diameter = 1
    var nt = n
    while (nt > 1) {
        diameter += 2
        nt /= k
    }
    val r = Random(System.currentTimeMillis())
    while (true) {
        val a = r.nextInt(n) + 1
        val c = r.nextInt(n) + 1
        if (a == c) {
            continue
        }
        val pathElems = mutableListOf<Int>()
        for (b in 1..n) {
            if (b != a && b != c) {
                println("? $a $b $c")
                if (readLine()!![0] == 'Y') {
                    pathElems.add(b)
                }
            }
        }
        if (pathElems.size + 2 != diameter) {
            continue
        }
        val path = IntArray(diameter)
        path[0] = a
        path[diameter - 1] = c
        fun findPath(from: Int, to: Int, elems: List<Int>) {
            if (from + 1 == to) {
                return
            }
            val d = elems.random(r)
            val left = mutableListOf<Int>()
            val right = mutableListOf<Int>()
            for (e in elems) {
                if (e != d) {
                    println("? ${path[from]} $e $d")
                    if (readLine()!![0] == 'Y') {
                        left.add(e)
                    } else {
                        right.add(e)
                    }
                }
            }
            val mid = from + left.size + 1
            path[mid] = d
            findPath(from, mid, left)
            findPath(mid, to, right)
        }
        findPath(0, diameter - 1, pathElems)
        println("! ${path[diameter / 2]}")
        return
    }
}