import java.io.PrintWriter
import java.util.*

fun solve() {
    var (n, K) = na()
    var a = na().toIntArray()
    a.sort()
    var dp = mutableListOf<IntArray>()
    for(i in 0..n-1){
        dp.add(IntArray(n))
    }
    for(i in 0..n-1){
        for(j in 0..n-1){
            dp[i][j] = -1000000000
        }
    }

    for(len in 2..n step 2){
        for(i in 0..n-1-len+1){
            var j = i+len-1
            if(len == 2){
                dp[i][j] = a[j] - a[i]
            }else{
                for(k in i+1..j-1 step 2){
                    dp[i][j] = Math.max(dp[i][j], dp[i][k] + dp[k+1][j])
                }
                dp[i][j] = Math.max(dp[i][j], a[j] - a[i] + dp[i+1][j-1])
            }
        }
    }
    
    var ep = mutableListOf<IntArray>()
    for(i in 0..K){
        ep.add(IntArray(n+1))
    }
    for(i in 0..K){
        for(j in 0..n){
            ep[i][j] = -1000000000
        }
    }
    ep[0][0] = 0
    for(i in 0..K){
        for(j in 0..n){
            if(ep[i][j] < 0){
                continue
            }
            if(j < n){
                ep[i][j+1] = Math.max(ep[i][j+1], ep[i][j])
            }
            for(t in 2..n-j step 2){
                if(i+t/2 <= K){
                    ep[i+t/2][j+t] = Math.max(ep[i+t/2][j+t], ep[i][j] + dp[j][j+t-1])
                }
            }
        }
    }

    var ans = 0
    for(i in 0..K){
        ans = Math.max(ans, ep[i][n])
    }
    out.println(ans)
}

val out = PrintWriter(System.out)

fun main() {
    solve()
    out.flush()
}

fun nline() = readLine()!!
fun ni() = nline().toInt()
fun nl() = nline().toLong()
fun nd() = nline().toDouble()
fun nas() = nline().split(" ")
fun na() = nas().map { it.toInt() }
fun nal() = nas().map { it.toLong() }

fun tr(x: Any) = System.err.println(x)
fun tr(x: IntArray) = System.err.println(Arrays.toString(x))
fun tr(x: Array<Any>) = System.err.println(Arrays.deepToString(x))