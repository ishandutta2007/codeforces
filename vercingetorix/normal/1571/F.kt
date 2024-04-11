var d = Array(5050, {-1})
fun main() {
    var (n,m) = readv()
    var ans = Array(n, {0})
    var q = MutableList<Pair<Int, Int>>(0, {Pair(0,0 )})
    var sum = 0
    for(i in 0 until n) {
        var (k, t) = readv()
        if(t == 1) {
            ans[i] = m - k + 1
            m -= k
        }
        else {
            q.add(Pair(k, i))
            sum += k
        }
    }
    if (sum > m) {
        println(-1)
        return
    }
    var m0 = (m+1)/2
    var m1 = m-m0
    var p0 = 1
    var p1 = 2
    var k = q.size
    if (k>0) {
        d[0] = 0
        for(ii in 0 until(k)) {
            for(nvr in 0..3000) {
                var nv = 3000-nvr
                if(nv >= q[ii].first && d[nv] == -1 && d[nv-q[ii].first] >= 0) d[nv] = ii
            }
        }
        for(fh in 0..3000) {
            if(fh <= m0 && fh <= sum && sum - fh <= m1 && d[fh] >= 0) {
                var pt = fh
                while(pt > 0) {
                    ans[q[d[pt]].second] = p0
                    p0 += 2*q[d[pt]].first
                    pt -= q[d[pt]].first
                }
                for(ii in 0 until(k)) {
                    if(ans[q[ii].second] == 0) {
                        ans[q[ii].second] = p1
                        p1 += 2*q[ii].first
                    }
                }
                println(ans.joinToString(" "))
                return
            }
        }
        println(-1)
    }
    else {
        println(ans.joinToString(" "))
    }

}

private fun read() = readLine()!!.toInt()
private fun readv() = readLine()!!.split(" ").map {it.toInt()}