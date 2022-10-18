import kotlin.math.*

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readLong() = readLn().toLong()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLongs() = readStrings().map { it.toLong() }

fun cal(l: Int, r: Int, b: Array <Array <IntArray>>, lg2: IntArray): Long{
    val z = lg2[r - l + 1]
    var pos: Int
    if (b[z][l][0] < b[z][r - (1 shl z) + 1][0]){
        pos = b[z][l][1]
    }
    else{
        pos = b[z][r - (1 shl z) + 1][1]
    }
    var ans = 1L * b[0][pos][0] * (pos - l + 1) * (r - pos + 1)
    if (pos != l){
        ans += cal(l, pos - 1, b, lg2)
    }
    if (pos != r){
        ans += cal(pos + 1, r, b, lg2)
    }
    return ans
}

fun main(){
    val (n, m) = readInts()
    val lg2 = IntArray(m + 1)
    lg2[1] = 0
    for (i in 2..m){
        lg2[i] = lg2[i / 2] + 1
    }
    val lm = lg2[m] + 1
    val popcnt = IntArray(32)
    for (i in 0..31){
        for (j in 0..4){
            if (i and (1 shl j) != 0){
                popcnt[i]++
            }
        }
    }
    val a = Array(n){ CharArray(m) }
    for (i in 0..n-1){
        val s = readLn()
        for (j in 0..m-1){
            a[i][j] = s[j]
        }
    }
    val ans_mask = LongArray(32)
    for (mask in 1..31){
        val b = Array(lm){ Array(m) { IntArray(2) } }
        for (j in 0..m-1){
            b[0][j][1] = j
        }
        for (i in 0..n-1){
            for (j in 0..m-1){
                if (mask and (1 shl (a[i][j].toInt() - 65)) != 0){
                    b[0][j][0]++
                }
                else{
                    b[0][j][0] = 0
                }
            }
            for (k in 1..lm-1){
                for (j in 0..m-(1 shl k)){
                    if (b[k - 1][j][0] < b[k - 1][j + (1 shl (k - 1))][0]){
                        b[k][j] = b[k - 1][j]
                    }
                    else{
                        b[k][j] = b[k - 1][j + (1 shl (k - 1))]
                    }
                }
            }
            ans_mask[mask] += cal(0, m - 1, b, lg2)
        }
    }
    val ans = LongArray(5)
    for (mask in 1..31){
        for (tmask in 1..mask-1){
            if (tmask and mask == tmask){
                ans_mask[mask] -= ans_mask[tmask]
            }
        }
        ans[popcnt[mask] - 1] += ans_mask[mask]
    }
    println(ans.joinToString(separator = " "))
}