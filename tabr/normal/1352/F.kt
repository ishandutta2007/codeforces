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
    var tt=readint()
    while(tt-- > 0){
        var (a,b,c)=readints()
        var ans=""
        if(a>0){
            for(i in 0..a){
                ans+='0'
            }
        }
        if(c>0){
            for(i in 0..c){
                ans+='1'
            }
        }
        if(a>0&&c>0){
            b--
        }
        if(a==0&&c==0){
            b++
        }
        if(c>0&&b>0){
            for(i in 0 until b){
                if(i%2==0){
                    ans+='0'
                }else{
                    ans+='1'
                }
            }
        }else if(b>0){
            for(i in 0 until b){
                if(i%2==1){
                    ans+='0'
                }else{
                    ans+='1'
                }
            }
        }
        println(ans)
    }
}