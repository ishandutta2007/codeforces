private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs

fun sol(){
    
    var(x,y)=readLine()!!.split(' ').map(String::toInt) 
    var r = Math.min(x,y)
    var a = r-1
    var b = x-a
    var c = y-a
    print(a)
    print(" ")
    print(b)
    print(" ")
    print(c)
    println()
}

fun main(){
    val T = readInt()
    for(i in 1..T) sol()
}