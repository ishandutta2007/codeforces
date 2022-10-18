private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun main(){
    var tt = readInt()
    for(qq in 1..tt){
        var n = readInt()
        if(n < 1000){
            println(n)
        }else if(n < 999500){
            n /= 100
            if(n % 10 >= 5){
                n += 10
            }
            n /= 10
            print(n)
            println("K")
        }else{
            n /= 100000
            if(n%10>=5){
                n+=10
            }
            n/=10
            print(n)
            println("M")
        }
    }
    
}