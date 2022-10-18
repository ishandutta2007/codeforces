import java.util.*

fun main(args: Array<String>){

    val scan = Scanner(System.`in`)

    val n = scan.nextInt()

    val r = ArrayList<Pair<Int, Int>>(n)
    r.add(Pair(0, -1))
    for(i in 1..n) r.add(Pair(scan.nextInt(), i))

    r.sortBy { it.first }
    //for(i in 1..n) println(r[i])

    val ans = ArrayList<Pair<Int, Int>>()
    for(i in 1..n){
        if(ans.isEmpty() || r[i].first > ans.last().second){
            ans.add(Pair(r[i].second, r[i].first))
        }
        if(ans.size >= 3) break
    }

    if(ans.size < 3) println("-1 -1 -1")
    else println("${ans[0].first} ${ans[1].first} ${ans[2].first}")

}