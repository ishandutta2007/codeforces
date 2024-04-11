var pm = Array<Long>(200, {0})
var pp = Array<Long>(200, {0})
const val mod : Long = 998244353

fun main() {
    var inm = invmod(1000000, mod)
    var (n,a,b) = readv()
    var vipx = Array(a+1, {0})
    var vipy = Array(b+1, {0})
    vipx[0] = 1
    vipx[a] = 1
    vipy[0] = 1
    vipy[b] = 1
    repeat(n) {
        var (x,y,p) = readv()
        var pt = p*inm%mod
        vipx[x] = 1
        vipy[y] = 1
        pp[x+y] = (pp[x+y] + (mod+1-pp[x+y])*pt)%mod
        pm[x-y+100] = (pm[x-y+100] + (mod+1-pm[x-y+100])*pt)%mod
    }
    var vx : MutableList<Int> = mutableListOf()
    var vy : MutableList<Int> = mutableListOf()
    for (i in 0..a) if(vipx[i] == 1) vx.add(i)
    for (i in 0..b) if(vipy[i] == 1) vy.add(i)
    var ans : Long = (vx.size-1).toLong()*(vy.size-1)
//    println(ans)
    for(i in 0 until vx.size - 1) {
        for(j in 0 until vy.size - 1) {
            var nx = vx[i]
            var mx = vx[i+1]
            var ny = vy[j]
            var my = vy[j+1]
            for (sm in nx+ny+1 until mx+my) {
                ans = (ans + pp[sm])%mod
                for (df in nx-my+101 until mx-ny+100) {
                    var xpy = sm
                    var xmy = df - 100
                    var x2 = xpy+xmy
                    var y2 = xpy-xmy
                    if(x2>2*nx && x2<2*mx && y2>2*ny && y2<2*my) {
                        ans = (ans + pp[sm]*pm[df])%mod
                    }
//                    ans = (ans + pm[df])%mod
                }
            }
            for (df in nx-my+101 until mx-ny+100) {
                ans = (ans + pm[df])%mod
            }

        }

    }
    println(ans)
}

private fun read() = readLine()!!.toInt()
private fun readv() = readLine()!!.split(" ").map {it.toInt()}

fun gcdp (a:Long, b:Long, xw:Long, yw:Long) : Pair<Long, Pair<Long, Long>> {
    var x:Long = xw
    var y:Long = yw
    if (a == 0L) {
        x = 0
        y = 1
        return Pair(b, Pair(x, y))
    }
    var f = gcdp(b%a, a, 0, 0)
    var d = f.first
    var x1 = f.second.first
    var y1 = f.second.second
    x = y1 - (b / a) * x1
    y = x1
    return Pair(d, Pair(x,y))
}

fun invmod(a : Long, modulo : Long) : Long{
    var f = gcdp(a, modulo, 0, 0)
    var g = f.first
    var x = f.second.first
    var y = f.second.second
    if (g != 1L)
    {
        return -1
    }
    else {
        x = (x % modulo + modulo) % modulo
        return x
    }
}