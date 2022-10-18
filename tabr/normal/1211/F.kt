import java.util.*
fun readln() = readLine()!!
fun readint() = readln().toInt() 
fun readlong() = readln().toLong() 
fun readdouble() = readln().toDouble()
fun readstrings() = readln().split(" ")
fun readints() = readstrings().map { it.toInt() } 
fun readlongs() = readstrings().map { it.toLong() } 
fun readdoubles() = readstrings().map { it.toDouble() }

fun main() {
	var n=readint()
    val st = "kotlin"
    var g = Array<MutableSet<Int>>(36){mutableSetOf()}
    for(i in 0 until n){
        var s=readln()
        var x=0
        var y=0
        while(st[x]!=s[0])x++
        while(st[y]!=s[s.length-1])y++
      	y=(y+1)%6
        g[x*6+y].add(i+1)
    }
	var id=0
    var ans=Array<MutableList<Int>>(6){mutableListOf<Int>()}
    var ps=IntArray(6){100000000}
    ps[0]=0
    for(k in 0 until 6){
        if(ps[k]==100000000)continue
        var now=k
        while(true) {
            ps[now]=minOf(ps[now],id)
            var pos=now*6+now
            if(g[pos].size!=0){
                var z=g[pos].first()
                ans[k].add(z)
                g[pos].remove(z)
                id++
                continue
            }
            for(i in 0..5){
                pos=now*6+i
                if(g[pos].size!=0){
                    var z=g[pos].first()
                    ans[k].add(z)
                    g[pos].remove(z)
                    now=i
                    id++
                    break
                }
                if(i==5){
                    now=-1
                    break
                }
            }
            if(now==-1)break
        }
    }
    var s=mutableListOf<Int>()
    for(i in 0 until ans[0].size){
        
        for(j in 1 until 6){
            if(ps[j]==i){
                for(k in ans[j]){
                    s.add(k)
                }
            }
        }
        s.add(ans[0][i])
    }
    println(s.joinToString(" "))
}