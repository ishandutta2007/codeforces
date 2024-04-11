private fun readLongs() = readLine()!!.split(" ").map { it.toInt() }

fun main() {
 
    val (t) = readLongs()
    
    for(i in 1..t){
        val(n,k) = readLongs()
        var n1 = n/(k*k*k+k*k+k+1)
        var n2 = n1*k
        var n3 = n2*k
        var n4 = n3*k
        print("$n1 $n2 $n3 $n4\n")
    }
    
}