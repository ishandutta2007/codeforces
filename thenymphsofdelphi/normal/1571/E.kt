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
        val n = readInt()
        val s = readLn()
        val t = readLn()
        val a0 = IntArray(n); val a1 = IntArray(n);
        var ans = 0
        for (i in 0..n-4){
            if (t[i] == '1'){
                a0[i] = 1;
                a1[i + 3] = 1;
            }
        }
        for (i in 0..n-4){
            if (t[i] == '1'){
                if (a0[i + 1] == 1){
                    a1[i + 2] = 1
                }
                if (a1[i + 1] == 1){
                    a0[i + 2] = 1
                }
                if (a0[i + 2] == 1){
                    a1[i + 1] = 1
                }
                if (a1[i + 2] == 1){
                    a0[i + 1] = 1
                }
            }
        }
        for (i in 0..n-1){
            if (a0[i] == 1 && a1[i] == 1){
                ans = -1
                break
            }
            if (a0[i] == 1 && s[i] == ')'){
                ans += 1
            }
            if (a1[i] == 1 && s[i] == '('){
                ans += 1
            }
        }
        for (i in 0..n-4){
            if (t[i] == '1'){
                if (a0[i + 1] == 0 && a0[i + 2] == 0 && a1[i + 1] == 0 && a1[i + 2] == 0){
                    if (s[i + 1] == s[i + 2]){
                        ans += 1
                    }
                }
            }
        }
        println(ans)
    }
}