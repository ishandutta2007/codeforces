import java.util.*

fun main() {
    val jin = Scanner(System.`in`)
    var n = jin.nextLong()
    if (n == 1L) {
        println(1)
        return
    }
    for (p in 2L..1000000L) {
        if (n % p == 0L) {
            while (n % p == 0L){
                n /= p
            }
            if (n == 1L) {
                println(p)
            } else {
                println(1)
            }
            return
        }
    }
    println(n)
}