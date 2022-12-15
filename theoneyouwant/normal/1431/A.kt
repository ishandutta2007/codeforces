import java.io.*
import java.util.*
import kotlin.math.*

fun main() {
 
    val fs = FS(System.`in`)
 
    var t = fs.nextInt()
    
    for(i in 1..t){
        var n = fs.nextInt()
        var array = Array<Long>(n){0}
        var ans = 0.toLong()
        for(j in 0..n-1){
            array[j] = fs.nextLong()
            array[j] = -array[j]
        }
        array.sort()
        for(j in 0..n-1){
            array[j] = -array[j]
            ans = max(ans, array[j] * (j + 1))
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