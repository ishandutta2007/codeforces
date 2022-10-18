fun readln() = readLine()!!
fun readint() = readln().toInt() 
fun readlong() = readln().toLong() 
fun readdouble() = readln().toDouble()
fun readstrings() = readln().split(" ")
fun readints() = readstrings().map { it.toInt() } 
fun readlongs() = readstrings().map { it.toLong() } 
fun readdoubles() = readstrings().map { it.toDouble() }

fun main(){
	var tt = readint()
    while(tt-- > 0) {
        var n = readint()
        var a = readints()
        var max = 0
        var ans = IntArray(n)
        var pmin = 1000000
        var nmax = -1000000
        var ppos = -1
        var npos = -1
        for(i in 0 until n) {
            if(a[i] > 0) {
                max += a[i]
                ans[i] = 1
                pmin = minOf(pmin, a[i])
                if(a[i] == pmin) {
                    ppos = i
                }
            }
            if(a[i] < 0) {
                nmax = maxOf(nmax, a[i])
                if(a[i] == nmax) {
                    npos = i
                }
            }
        }
        if(max - pmin >= max + nmax) {
            println(max - pmin)
            ans[ppos] = 0
        } else {
            println(max + nmax)
            ans[npos] = 1
        }
        println(ans.joinToString(""))
    }
}