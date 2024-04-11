fun readln() = readLine()!!
fun readint() = readln().toInt() 
fun readlong() = readln().toLong() 
fun readdouble() = readln().toDouble()
fun readstrings() = readln().split(" ")
fun readints() = readstrings().map { it.toInt() } 
fun readlongs() = readstrings().map { it.toLong() } 
fun readdoubles() = readstrings().map { it.toDouble() }

fun main(){
    var m=readint()
    var b=readints()
    var c=0
    var a=IntArray(m)
    for(i in m-1 downTo 0){
        if(b[i]==-1){
            c++
        }
        a[i]=c
    }
    println(c)
    for(i in 0 until c){
        var j=i
        var sz=0
        var ans = mutableListOf<Int>()
        while(b[j]!=-1){
            ans.add(b[j])
            j+=a[j]
            sz++
        }
        print("${sz} ")
        println(ans.joinToString(" "))
    }
}