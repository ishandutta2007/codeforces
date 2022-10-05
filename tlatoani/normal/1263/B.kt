import java.util.*

fun main() {
    val jin = Scanner(System.`in`)
    for (c in 1..jin.nextInt()) {
        val n = jin.nextInt()
        val pins = Array(n) { jin.next() }
        val set = mutableSetOf<String>()
        val answer = Array(n) { "" }
        for (j in 0 until n) {
            val pin = pins[j]
            if (!set.contains(pin)) {
                set.add(pin)
                pins[j] = ""
                answer[j] = pin
            }
        }
        var changes = 0
        for (j in 0 until n) {
            if (pins[j] != "") {
                changes++
                for (d in 0..39) {
                    val array = pins[j].toCharArray()
                    array[d / 10] = (d % 10).toString()[0]
                    if (!set.contains(String(array))) {
                        set.add(String(array))
                        answer[j] = String(array)
                        break
                    }
                }
            }
        }
        println(changes)
        for (pin in answer) {
            println(pin)
        }
    }
}