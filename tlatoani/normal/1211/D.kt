import java.util.*

fun main() {
    val jin = Scanner(System.`in`)
    val n = jin.nextInt()
    val a = jin.nextInt()
    val b = jin.nextInt()
    val k = jin.nextInt()
    val players = TreeMap<Int, Int>()
    for (i in 1..n) {
        val rating = jin.nextInt()
        players[rating] = (players[rating] ?: 0) + 1
    }
    val ratings = players.keys.toList()
    var answer = 0
    if (a < b) {
        for (rating in ratings.reversed()) {
            if (rating % k == 0 && players.containsKey(rating / k)) {
                while (players[rating]!! >= b && players[rating / k]!! >= a) {
                    players[rating] = players[rating]!! - b
                    players[rating / k] = players[rating / k]!! - a
                    answer++
                }
            }
        }
    } else {
        for (rating in ratings) {
            if (players.containsKey(k * rating)) {
                while (players[rating]!! >= a && players[k * rating]!! >= b) {
                    players[rating] = players[rating]!! - a
                    players[rating * k] = players[rating * k]!! - b
                    answer++
                }
            }
        }
    }
    println(answer)
}