import java.util.*

val readQueue = ArrayDeque<String>()

fun getInput(): String {
    if (readQueue.isEmpty()) readLine()?.split(' ', '\n')?.let { readQueue.addAll(it) }
    return readQueue.pop()
}

fun getInt(): Int {
    return getInput().toInt()
}

fun main() {
    var T = getInt()

    while (T-- > 0) {

        val a = getInt()
        val b = getInt()
        val p = getInt()

        val s = getInput()
        val n = s.length

        val dp = MutableList(n) { 0L }
        var lsta = n - 1
        var lstb = n - 1

        var ans = n
        for (i in n - 2 downTo 0) {
            if (s[i] == 'A'){
                dp[i] = dp[lstb] + a;
                lsta = i
            }
            else{
                dp[i] = dp[lsta] + b
                lstb = i
            }
            if(dp[i] <= p) ans = i + 1
        }
//        println(dp)

        println(ans)

    }
}