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
    val t = readInt()
    for(testid in 0..t-1){
        val n = readInt()
        val a = readInts()
        var bestneg = -100000
        var worstpos = 100000
        var total = 0
        for(x in a){
            if(x < 0){
                bestneg = max(bestneg, x);
            }
            if(x > 0){
                worstpos = min(worstpos, x);
                total += x;
            }
        }
        println(max(total - worstpos, total + bestneg))
        var ans = IntArray(n)
        var ptr = -1
        if(total - worstpos > total + bestneg){
            for(x in a){
                ++ptr;
                if(x <= 0){
                    ans[ptr] = 0;
                }
                else{
                    if(x == worstpos){worstpos = 100000; ans[ptr]=0;}
                    else {ans[ptr]=1;}
                }
            }
            println(ans.joinToString(""))
        }
        else{
            for(x in a){
                ++ptr;
                if(x <= 0){
                    if(x == bestneg){bestneg = -100000; ans[ptr]=1;}
                    else{ans[ptr]=0;}
                }
                else{
                    ans[ptr]=1;
                }
            }
            println(ans.joinToString(""))
        }
    }
}