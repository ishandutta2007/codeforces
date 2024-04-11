import java.util.*

fun main() {
    val out = StringBuilder()
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val answer = IntArray(n + 1)
        val taken = BooleanArray(n + 1)
        val tokenizer = StringTokenizer(readLine()!!)
        val rem = mutableListOf<Int>()
        var fulfilledWishes = 0
        var lastWish = 0
        for (j in 1..n) {
            val wish = tokenizer.nextToken().toInt()
            if (!taken[wish]) {
                answer[j] = wish
                taken[wish] = true
                fulfilledWishes++
            } else {
                rem.add(j)
                lastWish = wish
            }
        }
        if (rem.size == 1 && !taken[rem[0]]) {
            val other = (1..n).find { answer[it] == lastWish }!!
            answer[other] = rem[0]
            answer[rem[0]] = lastWish
        } else {
            val reallyRem = ArrayDeque<Int>()
            val equivalent = IntArray(n + 1)
            for (j in rem) {
                if (!taken[j]) {
                    equivalent[j] = j
                } else {
                    reallyRem.push(j)
                }
            }
            for (j in 1..n) {
                if (answer[j] != 0 && !taken[j]) {
                    equivalent[reallyRem.pop()] = j
                }
            }
            for (k in rem.indices) {
                answer[rem[k]] = equivalent[rem[(k + 1) % rem.size]]
            }
        }
        out.appendln(fulfilledWishes)
        out.appendln(answer.toList().subList(1, n + 1).joinToString(" "))
    }
    print(out)
}