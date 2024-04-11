import java.io.PrintWriter
import java.util.*

fun main(){
    val sc = Scanner(System.`in`)
    val pw = PrintWriter(System.out)
    val a = IntArray(4){ sc.nextInt() }
    a.sort()
    for (i in 0..2) a[i] = a[3] - a[i]
    println("${a[0]} ${a[1]} ${a[2]}")
}