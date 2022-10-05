import java.util.*

fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val tokenizer = StringTokenizer(readLine()!!)
        val array = LongArray(n) { tokenizer.nextToken().toLong() }
        val sum = array.sum()
        var xum = 0L
        for (a in array) {
            xum = xum xor a
        }
        var power = 1L
        while (power <= sum) {
            power *= 2L
        }
        val alpha = power - sum
        xum = xum xor alpha
        val beta = xum
        val gamma = xum + power
        println(3)
        println("$alpha $beta $gamma")
    }
}