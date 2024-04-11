import java.util.*

import kotlin.math.*

fun main() {
    val T = readLine()!!.toInt()

    repeat(T) {
        val (N, A, B) = readLine()!!.split(" ").map( {it.toInt()})
        val S = readLine()!!
        var res = N * A
        if(B > 0) {
            println(B * N + res)
        } else {
            var cons: Int = 0
            var ans = 0
            var v = 0
            for(i in 1 until N) {
                if(S[i] != S[i - 1] && S[i] == '0') {
                    ans++;
                }
            }
            v = max(v, ans+1);
            ans = 0
            for(i in 1 until N) {
                if(S[i] != S[i - 1] && S[i] == '1') {
                    ans++;
                }
            }
            v=max(v, ans+1)
            println(B * v + res)
        }
    }
}