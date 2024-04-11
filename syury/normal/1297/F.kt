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

class Zalupa(val a : Int, val b : Int, val c : Int)

fun main(){
    val t = readInt()
    for(testid in 0..t-1){
        val (n, m) = readInts();
        var s = ArrayList<Zalupa >();
        var t = ArrayList<Zalupa >();
        for(i in 0..n-1){
            val (x, y) = readInts();
            t.add(Zalupa(x, y, i));
        }
        var seq = IntArray(n);
        val tmp = t.sortedWith(compareBy({it.a}, {it.b}, {it.c}));
        for(z in tmp){s.add(z);}
        var x = 0;
        var i = 0;
        var day = 0;
        var q = PriorityQueue<Long>();
        while(i < n || !q.isEmpty()){
            if(q.isEmpty()){
                day = max(day, s[i].a);
            }
            while(i < n && s[i].a == day){
                q.add(n.toLong() * s[i].b.toLong() + s[i].c.toLong());
                ++i;
            }
            val sz = min(m, q.size);
            for(j in 0..sz-1){
                val t = q.poll();
                val idx = (t%n).toInt();
                val b = ((t - idx)/n).toInt();
                x = max(x, day - b);
                seq[idx] = day;
            }
            ++day;
        }
        println(x)
        println(seq.joinToString(" "));
    }
}