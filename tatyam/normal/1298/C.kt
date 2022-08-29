import java.io.PrintWriter
import java.util.*

fun main(){
    val sc = Scanner(System.`in`)
    val pw = PrintWriter(System.out)
    
    val n = sc.nextInt()
    val s = sc.next()
    var cnt = 0
    var ans = 0
    for (i in s) {
        if(i == 'x'){
            if(++cnt >= 3) ans++
        }
        else cnt = 0
    }
    pw.println(ans)
    
    pw.flush()
}