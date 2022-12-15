import java.io.*
import java.util.*
import kotlin.math.*

fun main() {
 
    val fs = FS(System.`in`)
 
    var t = fs.nextInt()
    
    for(i in 1..t){
        var x = fs.nextLong()
        var y = fs.nextLong()
        var temp = x
        while(y > temp) temp = temp * 10
        var ans = 0.toLong()
        while(temp>0){
            ans += y / temp
            y = y % temp
            if(temp>x){
                temp /= 10
            }
            else{
                if(temp == 1.toLong()) temp = 0
                temp /= x
            }
        
        }
        println(ans)
    }
    
}

class FS(stin: InputStream) {
    val read = BufferedReader(InputStreamReader(stin))
    var token = StringTokenizer("")
 
    tailrec fun next(): String {
        if(token.hasMoreTokens()) return token.nextToken()
        token = StringTokenizer(read.readLine())
        return next()
    }
 
    fun nextInt() = next().toInt()
    fun nextLong() = next().toLong()
    fun nextDouble() = next().toDouble()
}