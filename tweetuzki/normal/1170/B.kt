import java.util.*

fun main(args: Array<String>) = with(Scanner(System.`in`)) {
    val n = nextInt()
    val a = Array(n, { nextInt() })
    var ans = 0
    var no1 = 0
    var no2 = 0
    for (i in a) {
        if (no1 > i && no2 > i) ans++
        if (i > no1) {
            no2 = no1
            no1 = i
        } else if (i > no2) {
            no2 = i
        }
    }
    println(ans)
}