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
    val MX = 1000006
    val (k, n) = readInts()
    val p = readInts()
    val x = readInts()
    var used = ArrayList<Int>(1+MX)
    var u2 = ArrayList<Int>(n)
    var idx = ArrayList<Int>(1 + MX)
    var ptr = 0
    for(i in 0..n-1){u2.add(0);}
    for(i in 0..MX){
        used.add(0)
        while((ptr < n) && (x[ptr] < i)){ptr += 1}
        if((ptr < n) && (x[ptr] == i)){idx.add(ptr)}
        else{idx.add(-1);}
    }
    if(n < 3){
        println("YES")
        print(x[0])
        print(' ')
        println(p[0])
        if(n == 2){print(x[1])}
        else{print(x[0])}
        print(' ')
        println(p[0])
        return
    }
    for(i in 0..1){
        for(j in (i+1)..2){
            val d = x[j] - x[i]
            for(pi in 0..k-1){
                if((d%p[pi] == 0) && (used[p[pi]] == 0)){
                    used[p[pi]] = 1
                    var prv = -1
                    var curr = x[i]
                    var dd = p[pi]
                    while(curr < MX){
                        if(idx[curr] != -1){
                            u2[idx[curr]] = 1
                        }
                        curr += dd
                    }
                    var g = 0
                    var fst = -1
                    for(px in 0..n-1){
                        if(u2[px] == 0){
                            if(prv != -1){
                                g = gcd(g, x[px] - x[prv])
                            }
                            else{fst = px;}
                            prv = px
                        }
                        else{u2[px] = 0}
                    }
                    if(g == 0){
                        println("YES")
                        print(x[i]); print(' '); println(p[pi]);
                        if(fst == -1){print(x[i]);}else{print(x[fst]);}
                        print(' '); println(p[pi]);
                        return
                    }
                    var ok = 1
                    for(pk in 0..k-1){
                        if(g%p[pk] == 0){
                            println("YES")
                            print(x[i]); print(' '); println(p[pi]);
                            print(x[fst]); print(' '); println(p[pk]);
                            return
                        }
                    }
                }
                val kek = 0
            }
            for(pi in 0..k-1){
                used[p[pi]] = 0;
            }
        }
    }
    println("NO")
    //}
}