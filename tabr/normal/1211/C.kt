import java.util.PriorityQueue
fun readln() = readLine()!!
fun readint() = readln().toInt() 
fun readlong() = readln().toLong() 
fun readdouble() = readln().toDouble()
fun readstrings() = readln().split(" ")
fun readints() = readstrings().map { it.toInt() } 
fun readlongs() = readstrings().map { it.toLong() } 
fun readdoubles() = readstrings().map { it.toDouble() }

fun main() {
	var (nn,k)=readlongs()
    var n=nn.toInt()
    var a=LongArray(n)
    var b=LongArray(n)
    var c=LongArray(n)
    var d=LongArray(1000010)
    var eaten=0L
    var paid=0L
	for(i in 0 until n){
        var(x,y,z)=readlongs()
        a[i]=x
        b[i]=y
        c[i]=z
        d[c[i].toInt()]+=b[i]-a[i]
        eaten+=a[i]
        paid+=a[i]*c[i]
    }
    if(eaten>k){
        println(-1)
        return
    }
    for(i in 1..1000000){
        paid+=minOf(d[i], k-eaten)*i.toLong()
      	eaten+=minOf(d[i], k-eaten)
        if(eaten==k){
            break
        }
    }
    if(eaten!=k){
        println(-1)
    }else{
        println(paid)
    }
}