fun main(){
    val n = readLine()!!.toInt()
    val v = readLine()!!.split(" ").map { it.toInt() }
    var ans = 0
    var one=0
    var two=0
    for(i in 1..n){
        if(v[i-1]>=one){
            two = one
            one = v[i-1]
        } else if(v[i-1]>=two){
            two = v[i-1]
        }
        else ans++
    }
    println("$ans")
}