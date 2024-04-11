import java.util.*
fun readln() = readLine()!!
fun readint() = readln().toInt()
fun readlong() = readln().toLong()
fun readdouble() = readln().toDouble()
fun readstrings() = readln().split(" ")
fun readints() = readstrings().map { it.toInt() }
fun readlongs() = readstrings().map { it.toLong() }
fun readdoubles() = readstrings().map { it.toDouble() }

fun main() {
    var tt = readint()
    while (tt-- > 0) {
        var n=readint()
        var s = Array<String>(n){""}
        for(i in 0..n-1){
            var tmp=readln()
            s[i]=tmp
        }
        var ans="YES"
        for(i in n-2 downTo 0){
            for(j in n-2 downTo 0){
                if(s[i][j]=='1'){
                    if(s[i+1][j]=='0' && s[i][j+1]=='0'){
                        ans="NO"
                        break
                    }
                }
            }
        }
        println(ans)
    }
}

// kotlin sol.jar<in>out