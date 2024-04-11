import kotlin.math.*

fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val s = readLine()!!
        val a = readLine()!!

        var ans = 0

        for (i in 0 until n - 3) {
            if (a[i] == '1') {
                if (i + 1 < n - 3 && a[i + 1] == '1' || i + 3 < n - 3 && a[i + 3] == '1') {
                    ans = -1
                    break
                }

                if (i - 2 >= 0 && a[i - 2] == '1' || i + 2 < n - 3 && a[i + 2] == '1') {
                    ans += if (s[i] == '(') 0 else 1
                    ans += if (s[i + 1] == ')') 0 else 1

                    if (i + 2 >= n - 3 || a[i + 2] == '0') {
                        ans += if (s[i + 2] == '(') 0 else 1
                        ans += if (s[i + 3] == ')') 0 else 1
                    }
                } else {
                    var diff1 = 0
                    var diff2 = 0

                    for (j in 0 until 4) {
                        diff1 += if (s[i + j] == "()()"[j]) 0 else 1
                        diff2 += if (s[i + j] == "(())"[j]) 0 else 1
                    }

                    ans += min(diff1, diff2)
                }
            }
        }

        println(ans)
    }
}