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
	var n = readint()
   	var r = readints()
    var a = r[0]
    var b = -1
    var c = -1
    var ap = 1
    var bp = -1
    var cp = -1
    for (i in 1 until n) {
        if (b == -1 && r[i] != a) {
            bp = i+1
            b=r[i]
        }
        if(c==-1&&r[i]!=a&&r[i]!=b){
            cp=i+1
            c=r[i]
            break
        }
    }
    if (c==-1) {
        println("-1 -1 -1")
    } else {
        var list = arrayOf<Pair<Int,Int>>(Pair(a,ap),Pair(b,bp),Pair(c,cp))
        list.sortBy({it.first})
        ap=list[0].second
        bp=list[1].second
        cp=list[2].second
        println("$ap $bp $cp")
    }
}