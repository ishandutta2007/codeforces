fun main() {
    repeat(readLine()!!.toInt()) {
        val s = readLine()!!

        var hasLess = false
        var hasGreater = false

        for (c in s) {
            if (c == '<') {
                hasLess = true
            } else if (c == '>') {
                hasGreater = true
            }
        }

        println(when {
            hasLess && hasGreater -> '?'
            hasLess -> '<'
            hasGreater -> '>'
            else -> '='
        })
    }
}