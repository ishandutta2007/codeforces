import java.util.*

fun main(args: Array<String>){

    val scan = Scanner(System.`in`)

    val n = scan.nextInt()
    val k = scan.nextLong()

    val a = ArrayList<Triple<Long, Long, Long>>(n)

    var cnt = 0L
    var ans = 0L

    for(i in 0 until n){
        val aa = scan.nextLong()
        val bb = scan.nextLong()
        val cc = scan.nextLong()
        a.add(Triple(aa, bb, cc))
        cnt += aa
        ans += aa * cc
    }

    //System.err.println("$cnt $ans")

    if(cnt > k){
        println("-1")
        return
    }

    var p = 0
    a.sortBy { it.third }
    while(cnt < k){
        if(p >= n) break
        val t = Math.min(k - cnt, a[p].second - a[p].first)
        ans += a[p].third * t
        cnt += t
        p++
    }

    //System.err.println("$cnt $ans")
    if(cnt < k){
        println("-1")
        return
    }

    println(ans)

}