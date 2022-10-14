import java.util.*

import kotlin.math.*

fun dist(a: Int, b: Int, c: Int, d: Int) : Long {
    return abs(d-b).toLong()+abs(c-a).toLong();
}
fun works(a: IntArray, l: Int, r: Int) : Boolean {

    for(i in l..r) {
        for(j in i+1..r) {
            for(k in j+1..r) {
                assert(i != j && j != k)
                val dist1 = dist(i, a[i], j, a[j])
                val dist2 = dist(i, a[i], k, a[k])
                val dist3 = dist(j, a[j], k, a[k])
                if(dist2 == dist1 + dist3)
                    return false;
            }
        }
    }
    return true;
}
fun main() {
    val T = readLine()!!.toInt()

    repeat(T) {
        val N = readLine()!!.toInt()
        val A = readLine()!!.split(" ").map( {it.toInt() }).toIntArray()
//        var l = 0
        var r = 0
        var ans = 0L
        for(l in 0..N-1) {
            while(r < N && works(A, l, r)) {
                r++
            }
//            print(l)
//            print(" ")
//            print(r)
//            println()

            ans += (r - l)
        }

        println(ans)
    }
}