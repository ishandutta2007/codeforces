import java.util.*

fun main() {
    var tokenizer = StringTokenizer(readLine()!!)
    tokenizer.nextToken()
    val k = tokenizer.nextToken().toInt()
    val query = mutableSetOf<Int>()
    fun makeQuery(): Pair<Int, Int> {
        println("? " + query.joinToString(" ", "", ""))
        tokenizer = StringTokenizer(readLine()!!)
        val j = tokenizer.nextToken().toInt()
        val v = tokenizer.nextToken().toInt()
        return Pair(j, v)
    }
    for (j in 1..k) {
        query.add(j)
    }
    val pivot = makeQuery()
    query.remove(pivot.first)
    query.add(k + 1)
    var res = makeQuery()
    val isGreater = res.second > pivot.second
    var amtLess = 0
    query.add(pivot.first)
    for (j in 1..k) {
        if (j != pivot.first) {
            query.remove(j)
            res = makeQuery()
            if (isGreater) {
                if (res.first != pivot.first) {
                    amtLess++
                }
            } else {
                if (res.first == pivot.first) {
                    amtLess++
                }
            }
            query.add(j)
        }
    }
    println("! ${amtLess + 1}")
}