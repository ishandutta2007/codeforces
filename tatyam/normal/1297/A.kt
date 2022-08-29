import java.io.PrintWriter
import java.util.*
import kotlin.math.*

fun main(){
    val sc = Scanner(System.`in`)
    val pw = PrintWriter(System.out)


    val t = sc.nextInt()
    for (i in 0 until t) {
        val n = sc.nextInt()
        when {
            n < 1000 -> pw.println(n)
            n < 999500 -> pw.println("${(n + 500) / 1000}K")
            else -> pw.println("${(n + 500000) / 1000000}M")
        }
    }

    pw.flush()
}