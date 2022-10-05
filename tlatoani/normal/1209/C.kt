import java.util.*

fun main() {
    val jin = Scanner(System.`in`)
    for (c in 1..jin.nextLine().toInt()) {
        val n = jin.nextLine().toInt()
        val digits = jin.nextLine().map { chara -> chara - '0' }
        val answer = IntArray(n)
        var possible = false
        for (split in 0..9) {
            val left = digits.indexOfFirst { d -> d > split }
            val right = digits.indexOfLast { d -> d < split }
            if (left != -1 && right != -1 && left < right && digits.subList(left, right).contains(split)) {
                continue
            }
            var prevBelow = 0
            var prevAbove = split + 1
            var posHere = true
            for (i in 0 until n) {
                if (digits[i] < split) {
                    if (prevBelow > digits[i]) {
                        posHere = false
                        break
                    }
                    answer[i] = 1
                    prevBelow = digits[i]
                } else if (digits[i] > split) {
                    if (prevAbove > digits[i]) {
                        posHere = false
                        break
                    }
                    answer[i] = 2
                    prevAbove = digits[i]
                } else if (i < left) {
                    answer[i] = 2
                } else {
                    answer[i] = 1
                }
            }
            if (posHere) {
                possible = true
                break
            }
        }
        if (possible) {
            println(answer.joinToString("", "", ""))
        } else {
            println("-")
        }
    }
}