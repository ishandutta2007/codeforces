fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val s = readLine()!!
        var answer = "nO"
        for (a in listOf(-1, 1)) {
            for (b in listOf(-1, 1)) {
                for (c in listOf(-1, 1)) {
                    var works = true
                    var curr = 0
                    for (chara in s) {
                        curr += when (chara) {
                            'A' -> a
                            'B' -> b
                            else -> c
                        }
                        if (curr < 0) {
                            works = false
                        }
                    }
                    if (curr != 0) {
                        works = false
                    }
                    if (works) {
                        answer = "yEs"
                    }
                }
            }
        }
        println(answer)
    }
}