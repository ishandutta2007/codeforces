fun main(args: Array<String>) {
val (n,m) = readLine()!!.split(" ").map(String::toInt)
val b : MutableList<String> = mutableListOf()
for(i in 1..n){
b.add(readLine()!!.trim())
}
var yr = 0
var yc = 0
var br = 0
var bc = 0
var tr = 0
var tc = 0
for(i in 0..n-1){
    for(j in 0..m-1){
        if(b[i][j] == 'Y'){
            yr = i
            yc = j
        }
        if(b[i][j] == 'B'){
            br = i
            bc = j
        }
        if(b[i][j] == 'T'){
            tr = i
            tc = j
        }
    }
}

val q = Array<Int>(40*40*40*40, {i -> 0})
var qh = 0
var qt = 0
val scode = ((yr*40+yc)*40+br)*40+bc
val d = Array<Int>(40*40*40*40, {i -> 999999999})
val prevs = Array<Int>(40*40*40*40, {i -> -1})
val moves = Array<Char>(40*40*40*40, {i -> '.'})
d[scode] = 0
q[qh++] = scode
val dr = arrayOf(1, 0, -1, 0)
val dc = arrayOf(0, 1, 0, -1)
var dirs = "senw"
var dirx = "SENW"
var last = -1
while(qt < qh){
    val cur = q[qt++]
    yr = cur/40/40/40
    yc = cur/40/40%40
    br = cur/40%40
    bc = cur%40
    if(br == tr && bc == tc){
        last = cur
        break
    }
    for(k in 0..3){
        val nyr = yr + dr[k]
        val nyc = yc + dc[k]
        if(0 <= nyr && nyr < n && 0  <= nyc && nyc < m && b[nyr][nyc] != 'X'){
            var nbr = br
            var nbc = bc
            var dir = dirs[k]
            if(nbr == nyr && nbc == nyc){
                nbr += dr[k]
                nbc += dc[k]
                if(!(0 <= nbr && nbr < n && 0  <= nbc && nbc < m && b[nbr][nbc] != 'X')){
                    continue
                }
                dir = dirx[k]
            }
            val ncode = ((nyr*40+nyc)*40+nbr)*40+nbc
            if(d[ncode] > d[cur] + 1){
                d[ncode] = d[cur] + 1
                moves[ncode] = dir
                prevs[ncode] = cur
                q[qh++] = ncode
            }
        }
    }
}
if(last == -1){
    println("NO")
}else{
    println("YES")
    val route = Array<Char>(d[last], {i -> '.'})
    var cur = last
    while(cur != scode){
        route[d[cur]-1] = moves[cur]
        cur = prevs[cur]
    }
    for(t in route){
        print(t)
    }
}

}