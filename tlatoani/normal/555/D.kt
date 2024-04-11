import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val (n, m) = jin.readLine().split(" ").map { it.toInt() }
    val unsorted = listOf(Int.MIN_VALUE) + jin.readLine().split(" ").map { it.toInt() }
    val xs = unsorted.sorted()
    val xix = mutableMapOf<Int, Int>()
    val ixi = mutableMapOf<Int, Int>()
    for (j in 0..n) {
        xix[xs[j]] = j
        ixi[unsorted[j]] = j
    }
    val out = StringBuilder()
    for (j in 1..m) {
        val (k, l) = jin.readLine().split(" ").map { it.toInt() }
        var length = l
        var last = 0
        var curr = xix[unsorted[k]]!!
        var d = true
        while (true) {
            //println("last = $last, curr = $curr, length = $length, d = $d")
            if (d) {
                var upper = n
                var lower = curr
                while (upper > lower) {
                    val mid = (upper + lower + 1) / 2
                    if (xs[mid] - xs[curr] <= length) {
                        lower = mid
                    } else {
                        upper = mid - 1
                    }
                }
                length -= xs[upper] - xs[curr]
                if (last == upper) {
                    if (curr == upper) {
                        out.appendln(ixi[xs[curr]])
                        break
                    } else {
                        if ((length / (xs[upper] - xs[curr])) % 2 == 1) {
                            d = !d
                            val temp = upper
                            upper = curr
                            curr = temp
                        }
                        length %= xs[upper] - xs[curr]
                    }
                }
                last = curr
                curr = upper
            } else {
                var upper = curr
                var lower = 1
                while (upper > lower) {
                    val mid = (upper + lower) / 2
                    if (xs[curr] - xs[mid] <= length) {
                        upper = mid
                    } else {
                        lower = mid + 1
                    }
                }
                length -= xs[curr] - xs[upper]
                if (last == upper) {
                    if (curr == upper) {
                        out.appendln(ixi[xs[curr]])
                        break
                    } else {
                        if ((length / (xs[curr] - xs[upper])) % 2 == 1) {
                            d = !d
                            val temp = upper
                            upper = curr
                            curr = temp
                        }
                        length %= xs[curr] - xs[upper]
                    }
                }
                last = curr
                curr = upper
            }
            d = !d
        }
    }
    print(out)
}

/*

3 1
0 3 5
2 3


 */


/*

4 1
0 1 15 16
4 257


 */