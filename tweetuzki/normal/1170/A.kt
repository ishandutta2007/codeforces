import java.util.*

fun main(args: Array<String>) = with(Scanner(System.`in`)) {
    val q = nextInt()
    repeat(q) {
        val x = nextInt()
        val y = nextInt()
        val a = if (x < y) x - 1 else y - 1
        println("$a ${x - a} ${y - a}")
    }
}