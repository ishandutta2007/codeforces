fun readln() = readLine()!!
fun readint() = readln().toInt() 
fun readlong() = readln().toLong() 
fun readdouble() = readln().toDouble()
fun readstrings() = readln().split(" ")
fun readints() = readstrings().map { it.toInt() } 
fun readlongs() = readstrings().map { it.toLong() } 
fun readdoubles() = readstrings().map { it.toDouble() }

fun main(){
    var n =readint()
    var a=readints()
    var ans=0
    var m1=0
    var m2=0
    for(i in 0 until n){
        if(a[i]>=m1){
            m2=m1
            m1=a[i]
        }else if(a[i]>=m2){
            m2=a[i]
        }else{
            ans++
        }
    }
    println(ans)
}