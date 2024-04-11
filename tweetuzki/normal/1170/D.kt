import java.util.*

val maxn = 300000
var n = 0
var b = Array(maxn + 5) {0}
var k = 0
var a = Array(maxn + 5) { mutableListOf<Int>() }
var l = Array(maxn + 5) {0}
var r = Array(maxn + 5) {0}

fun main(args: Array<String>) = with(Scanner(System.`in`)) {
    n = nextInt()
    for (i in 1 .. n) {
        b[i] = nextInt()
        if (b[i] == -1) k++
    }
    for (i in 1 .. k) {
        l[i] = i - 1
        r[i] = i + 1
    }
    r[0] = 1
    l[k + 1] = k
    var pos = 1
    for (i in 1 .. n) {
        if (pos == k + 1) pos = r[0]
        if (b[i] == -1) {
            r[l[pos]] = r[pos]
            l[r[pos]] = l[pos]
        } else {
            a[pos].add(b[i])
        }
        pos = r[pos]
    }
    println(k)
    for (i in 1 .. k) {
        val c = a[i].size
        println("$c " + a[i].joinToString(" "))
    }
}