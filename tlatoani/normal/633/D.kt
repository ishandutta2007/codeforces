import java.util.*
import kotlin.math.max

fun main() {
    val jin = Scanner(System.`in`)
    val n = jin.nextInt()
    val array = LongArray(n) { jin.nextLong() }
    val accountedFor = mutableSetOf<Pair<Long, Long>>()
    val freq = mutableMapOf<Long, Int>()
    for (a in array) {
        freq[a] = (freq[a] ?: 0) + 1
    }
    var answer = freq[0] ?: 0
    for (a in array) {
        for (b in array) {
            if (accountedFor.contains(Pair(a, b))) {
                continue
            }
            if (a == b && freq[a]!! < 2) {
                continue
            }
            if (a == 0L && b == 0L)  {
                continue
            }
            val sequence = LinkedList<Long>()
            freq[a] = freq[a]!! - 1
            freq[b] = freq[b]!! - 1
            sequence.add(a)
            sequence.add(b)
            accountedFor.add(Pair(a, b))
            while (true) {
                while ((freq[sequence[1] - sequence[0]] ?: 0) > 0) {
                    val c = sequence[1] - sequence[0]
                    freq[c] = freq[c]!! - 1
                    accountedFor.add(Pair(c, sequence[0]))
                    sequence.addFirst(c)
                }
                //println("sequence = $sequence")
                answer = max(answer, sequence.size)
                if (sequence.size == 2) {
                    break
                }
                while (sequence.size > 2) {
                    freq[sequence.last] = freq[sequence.last]!! + 1
                    sequence.removeLast()
                }
            }
            while (true) {
                while ((freq[sequence[sequence.size - 2] + sequence.last] ?: 0) > 0) {
                    val c = sequence[sequence.size - 2] + sequence.last
                    freq[c] = freq[c]!! - 1
                    accountedFor.add(Pair(sequence.last, c))
                    sequence.addLast(c)
                }
                //println("sequence = $sequence")
                answer = max(answer, sequence.size)
                if (sequence.size == 2) {
                    break
                }
                while (sequence.size > 2) {
                    freq[sequence[0]] = freq[sequence[0]]!! + 1
                    sequence.removeFirst()
                }
            }
            freq[sequence[0]] = freq[sequence[0]]!! + 1
            freq[sequence[1]] = freq[sequence[1]]!! + 1
        }
    }
    println(answer)
}