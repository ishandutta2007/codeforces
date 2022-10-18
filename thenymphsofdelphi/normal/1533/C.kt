import kotlin.math.*

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readLong() = readLn().toLong()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLongs() = readStrings().map { it.toLong() }

fun main(){
    val q = readInt()
    repeat(q){
        val (n, k) = readInts()
        val s = readLn()
        var ck = Array(n) { i -> false}
        var realpos = Array(n) {i -> 0}
        var ans = 0
        var tol = 0
        for (i in 0..n-1){
            if (s[i] == '1'){
                tol++
            }
        }
        var pos = 0
        while (tol > 0){
            ans++
            ck[pos] = true
            if (s[pos] == '1'){
                tol--
                if (tol == 0){
                    break
                }
            }
            var idx = 0
            var nxtpos = -1
            for (i in 0..n-1){
                if (ck[i] == false){
                    realpos[idx] = i
                    if (i > pos && nxtpos == -1){
                        nxtpos = idx
                    }
                    idx++
                }
            }
            if (nxtpos == -1){
                nxtpos = 0
            }
            pos = realpos[(nxtpos + k - 1) % idx]
        }
        println(ans)
    }
}