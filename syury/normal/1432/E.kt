import java.util.*

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs

inline fun <T : Comparable<T> > min(x : T, y : T): T{
    if(x < y){return x;}
    else{return y;}
}

inline fun <T : Comparable<T> > max(x : T, y : T): T{
    if(x > y){return x;}
    else{return y;}
}

fun main(){
    val T = readInt()
    for(t in 1..T){
        var (nn, k) = readLongs()
        var n = nn.toInt()
        val s = readLn()
        var wasZeros = 0
        var rem = 0
        for(i in 0..n-1){
            if(s.get(i) == '1'){continue}
            var moves = i - wasZeros
            if(moves <= k){
                k -= moves
            }
            else{
                rem = moves - k.toInt()
                break
            }
            wasZeros++
        }
        var ans = CharArray(n)
        var ptr = wasZeros
        var zs = 0
        for(i in 0..wasZeros-1){
            ans[i] = '0'
        }
        for(i in 0..n-1){
            if(s.get(i) == '1'){
                ans[ptr++] = '1'
                if(rem == 1){
                    ans[ptr++] = '0'
                }
                --rem
            }
            else{
                if(zs > wasZeros){
                    ans[ptr++] = '0'
                }
                ++zs
            }
        }
        println(ans.joinToString(""))
    }
}