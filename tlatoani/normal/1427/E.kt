import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.random.Random
import kotlin.system.exitProcess

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    var x = jin.readLine().toLong()
    var operationAMT = 0
    val out = StringBuilder()
    fun add(x: Long, y: Long): Long {
        operationAMT++
        out.appendln("$x + $y")
        //println("$x + $y = ${x + y}")
        if (x + y == 1L) {
            println(operationAMT)
            print(out)
            exitProcess(0)
        }
        return x + y
    }
    fun xor(x: Long, y: Long): Long {
        operationAMT++
        out.appendln("$x ^ $y")
        //println("$x ^ $y = ${x xor y}")
        if (x xor y == 1L) {
            println(operationAMT)
            print(out)
            exitProcess(0)
        }
        return x xor y
    }
    fun gcd(x: Long, y: Long): Long {
        if (x > y) {
            return gcd(y, x)
        } else if (x == 0L) {
            return y
        } else {
            var e = 0
            while (x >= 1L shl e) {
                e++
            }
            var f = 0
            while (y >= 1L shl f) {
                f++
            }
            var xm = x
            for (j in 1..f - e) {
                xm = add(xm, xm)
            }
            return gcd(x, xor(xm, y))
        }
    }
    xor(x, x)
    val random = Random(System.currentTimeMillis())
    xLoop@while (true) {
        for (e in 1..29) {
            add(x * (1L shl (e - 1)), x * (1L shl (e - 1)))
        }
        var other = 0L
        for (e in 0..29) {
            if (random.nextBoolean()) {
                other = add(other, (1L shl e) * x)
            }
        }
        x = gcd(x, other)
        if (operationAMT > 100000) {
            val bs = LongArray(1000000)
            for (j in 0..999999) {
                for (k in 0..999999) {
                    bs[j] *= bs[j] xor bs[k]
                }
            }
        }
    }
}