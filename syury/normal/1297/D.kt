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

class P(val x: Int, val y: Int)

fun main(){
    val t = readInt()
    for(testid in 0..t-1){
        val (n, k) = readInts()
        val b = readInts()
        var aa = ArrayList<Pair<Int, Int> >();
        for(i in 0..n-1){
            aa.add(Pair<Int, Int>(b[i], i));
        }
        var aaa = aa.sortedWith(compareBy({it.first}, {it.second}));
        var a = IntArray(n);
        for(i in 0..n-1){
            a[i] = aaa[i].first;
        }
        var ex : Long;
        ex = 0
        var currex : Long;
        currex = 0
        for(i in n-2 downTo 0){
            if (a[i] < a[i + 1]){
                currex += a[i + 1] - a[i] - 1;
            }
            ex += currex;
        }
        var x : Long;
        x = 0;
        if(ex < k){
            x = (k - ex)/n;
            if(n * x != k - ex){
                ++x;
            }
        }
        var ans = LongArray(n);
        for(i in 0..n-1){
            ans[i] = 0;
        }
        var kek : Long;
        kek = k.toLong();
        currex = 0;
        for(i in n-1 downTo 0){
            if((i + 1 < n) && (a[i + 1] > a[i])){currex += a[i + 1] - a[i] - 1;}
            val add = min(kek, x + currex);
            kek -= add;
            ans[aaa[i].second] = add;
        }
        //println(a.joinToString(" "));
        println(ans.joinToString(" "));
    }
}