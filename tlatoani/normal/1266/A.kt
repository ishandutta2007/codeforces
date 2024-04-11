fun main() {
    for (c in 1..readLine()!!.toInt()) {
        var found0 = false
        var amtEven = 0
        var sum = 0
        for (chara in readLine()!!) {
            when (chara - '0') {
                0 -> { found0 = true; amtEven++ }
                2, 4, 6, 8 -> amtEven++
            }
            sum += chara - '0'
        }
        println(if (found0 && amtEven > 1 && sum % 3 == 0) "red" else "cyan")
    }
}