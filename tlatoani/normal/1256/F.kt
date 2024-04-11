import java.util.*

fun main() {
    val jin = Scanner(System.`in`)
    val builder = StringBuilder()
    for (c in 1..jin.nextInt()) {
        val n = jin.nextInt()
        val s = jin.next()
        val t = jin.next()
        val sSort = s.map { it }.sorted()
        val tSort = t.map { it }.sorted()
        if (sSort != tSort) {
            builder.append("NO\n")
            continue
        }
        val set = sSort.toSet()
        if (set.size < n) {
            builder.append("YES\n")
            continue
        }
        val freqS = IntArray(26)
        val freqT = IntArray(26)
        var parityS = 0
        var parityT = 0
        for (j in 0 until n) {
            for (c in 0 until s[j] - 'a') {
                parityS = parityS xor freqS[c]
            }
            for (c in 0 until t[j] - 'a') { // wow tj
                parityT = parityT xor freqT[c]
            }
            freqS[s[j] - 'a']++
            freqT[t[j] - 'a']++
        }
        builder.append(if ((parityS xor parityT) % 2 == 0) "YES\n" else "NO\n")
    }
    print(builder)
}