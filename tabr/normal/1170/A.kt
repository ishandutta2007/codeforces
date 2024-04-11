fun readln() = readLine()!!
fun readint() = readln().toInt() 
fun readlong() = readln().toLong() 
fun readdouble() = readln().toDouble()
fun readstrings() = readln().split(" ")
fun readints() = readstrings().map { it.toInt() } 
fun readlongs() = readstrings().map { it.toLong() } 
fun readdoubles() = readstrings().map { it.toDouble() }

fun main(){
    var t =readint()
    while(t-- > 0){
        var (x,y)=readints()
    	if(x<y){
            var z=y
            y=x
            x=z
        }
        println("${y-1} ${x-y+1} 1")
    }
}