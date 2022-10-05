import java.util.*

fun main() {
    val jin = Scanner(System.`in`)
    for (c in 1..jin.nextInt()) {
        val a = jin.nextInt()
        val b = jin.nextInt()
        if ((a + b) % 3 == 0 && a <= 2 * b && b <= 2 * a) {
            println("YES")
        } else {
            println("NO")
        }
    }
}