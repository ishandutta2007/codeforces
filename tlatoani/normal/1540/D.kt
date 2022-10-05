import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val n = 100352
    val lgbt = 10
    val b = 1 shl lgbt
    val nActual = jin.readLine().toInt()
    val indexes = Array(lgbt + 1) { IntArray(n) { it } }
    val values = Array(lgbt + 1) { IntArray(n) { it } }
    val tokenizer = StringTokenizer(jin.readLine())
    for (x in 0 until nActual) {
        values[0][x] = x - tokenizer.nextToken().toInt()
    }
    fun merge(k: Int, l: Int) {
        val end = k + (1 shl l)
        val mid = k + (1 shl (l - 1))
        var x = mid
        var y = k
        var z = k
        while (y < mid || x < end) {
            if (y < mid && (x == end || values[l - 1][y] + (x - mid) < values[l - 1][x])) {
                indexes[l][z] = indexes[l - 1][y];
                values[l][z] = values[l - 1][y] + (x - mid);
                y++;
            } else {
                indexes[l][z] = indexes[l - 1][x];
                values[l][z] = values[l - 1][x];
                x++;
            }
            z++
        }
    }
    val set = IntArray(n)
    fun assign(k: Int) {
        for (x in k until k + b) {
            set[indexes[lgbt][x]] = values[lgbt][x]
        }
    }
    fun find(k: Int, x: Int): Int {
        var upper = b
        var lower = 0
        while (upper > lower) {
            val mid = (upper + lower) / 2
            if (x + mid < values[lgbt][k + mid]) {
                upper = mid
            } else {
                lower = mid + 1
            }
        }
        return x + upper
    }
    fun update(k: Int) {
        var k = k
        for (l in 1..lgbt) {
            k -= k % (1 shl l)
            merge(k, l)
        }
        assign(k)
    }
    fun calc(k: Int): Int {
        var x = set[k]
        var k = k - (k % b) + b
        while (k < n) {
            x = find(k, x)
            k += b
        }
        return x
    }
    for (l in 1..lgbt) {
        for (k in 0 until n) {
            if (k % (1 shl l) == 0) {
                merge(k, l)
            }
        }
    }
    for (k in 0 until n) {
        if (k % b == 0) {
            assign(k)
        }
    }
    val out = StringBuilder()
    repeat(jin.readLine().toInt()) {
        val query = jin.readLine().split(" ").map { it.toInt() }
        if (query[0] == 1) {
            val k = query[1] - 1
            values[0][k] = k - query[2]
            update(k)
        } else {
            val k = query[1] - 1
            out.appendln(calc(k) + 1)
        }
    }
    print(out)
}