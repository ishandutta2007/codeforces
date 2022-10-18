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
        var n=readint()
        var s=readln()
        var x=1
        var a=IntArray(n)
        var s0=IntArray(n+1)
        var s1=IntArray(n+1)
        var b0=-1
        var b1=-1
        for(i in 0..n-1){
            if(s[i]=='0'){
                if(b0==-1){
                    a[i]=x
                    b1++
                    s1[b1]=x
                    x++
                }else{
                    var b=s0[b0]
                    a[i]=b
                    b0--
                    b1++
                    s1[b1]=b
                }
            }else{
                if(b1==-1){
                    a[i]=x
                    b0++
                    s0[b0]=x
                    x++
                }else{
                    var b=s1[b1]
                    a[i]=b
                    b1--
                    b0++
                    s0[b0]=b
                }
            }
        }
        println(x-1)
        println(a.joinToString(" "))
    }
}