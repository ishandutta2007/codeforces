import java.util.*
import java.lang.Math;


fun main(args: Array<String>) {
    val T = readLine()!!.toInt()
    repeat(T) {
        val n = readLine()!!.toInt()
        val a = readLine()!!.split(" ").map( {it.toInt()})
        var parity = 0
        for(i in 0 until n - 1) {
            if( (a[i + 1] - a[i]) % 2 == 0) {
                parity = 1;
            }
        }

        if(parity == 1)
            println("YES")
        else
            println("NO")
    }

}