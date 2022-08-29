import java.util.*

val sc = Scanner(System.`in`)

fun solve() {
    val n = sc.nextInt()
    var k = sc.nextInt()
    sc.nextLine()
    val s = sc.nextLine()
    var depth = 0
    var ans = 0
    for (i in 0 until n) {
        if (s[i] == '(') depth++
        else {
            depth--
            if (depth > 0 && k > 0){
                k--
                ans++
            }
            else if (depth == 0){
                ans++
            }
        }
    }
    println(ans)
}
fun main() {
    val t = sc.nextInt()
    for (i in 0 until t) solve()
}