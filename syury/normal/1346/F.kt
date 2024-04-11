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

inline fun div(s: Long, n: Int): Long{
    val k = n.toLong()
    if(s%k == 0L){return s/k;}
    else{return s/k + 1L;}
}

inline fun gcd(x: Int, y: Int): Int{
    if(x == 0){return y}
    else{
        var px = x
        var py = y
        while(px != 0){
            var tmp = px
            px = py%px
            py = tmp
        }
        return py
    }
}

fun main(){
    //val T = readInt()
    //for(t in 1..T){
    val (n, m, q) = readInts()
    var a = ArrayList<ArrayList<Int> >(n)
    var v = ArrayList<Long>(m)
    var h = ArrayList<Long>(n)
    var ans = ArrayList<Long>(q + 1)
    for(i in 0..n-1){h.add(0L);}
    for(i in 0..m-1){v.add(0L);}
    for(i in 0..n-1){
        var b = readInts()
        a.add(ArrayList<Int>(m))
        for(x in b){a[i].add(x)}
        for(j in 0..m-1){
            h[i] += a[i][j].toLong()
            v[j] += a[i][j].toLong()
        }
    }
    for(qi in 0..q){
        var cans = 0L
        var hsum = 0L
        var vmul = 0L
        var hmul = 0L
        var vsum = 0L
        var curr = 2000000000000000000L
        for(i in 0..n-1){hsum += h[i]; hmul += h[i] * i.toLong();}
        for(j in 0..m-1){vsum += v[j]; vmul += v[j] * j.toLong();}
        var carry = 0L
        var carrymul = 0L
        for(i in 0..n-1){
            var cu = carry * i.toLong() - carrymul - i.toLong() * (hsum - carry) + (hmul - carrymul)
            curr = min(curr, cu)
            carry += h[i]
            carrymul += h[i] * i.toLong()
        }
        cans += curr
        carrymul = 0L
        carry = 0L
        curr = 2000000000000000000L
        for(i in 0..m-1){
            var cu = carry * i.toLong() - carrymul - i.toLong() * (vsum - carry) + (vmul - carrymul)
            curr = min(curr, cu)
            carry += v[i]
            carrymul += v[i] * i.toLong()
        }
        cans += curr
        ans.add(cans)
        if(qi == q){break}
        var (i, j, z) = readInts()
        --i; --j;
        h[i] -= a[i][j].toLong(); v[j] -= a[i][j].toLong();
        a[i][j] = z;
        h[i] += z.toLong(); v[j] += z.toLong();
    }
    println(ans.joinToString(" "))
    //}
}