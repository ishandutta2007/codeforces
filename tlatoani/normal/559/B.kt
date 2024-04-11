fun main() {
    val s1 = readLine()!!.toCharArray()
    val s2 = readLine()!!.toCharArray()
    fun sort(s: CharArray, from: Int, to: Int) {
        if ((to - from) % 2 == 0) {
            val mid = (from + to) / 2
            sort(s, from, mid)
            sort(s, mid, to)
            var leq = true
            for (j in 0 until mid - from) {
                if (s[from + j] < s[mid + j]) {
                    break
                }
                if (s[from + j] > s[mid + j]) {
                    leq = false
                    break
                }
            }
            if (!leq) {
                for (j in 0 until mid - from) {
                    val a = s[from + j]
                    val b = s[mid + j]
                    s[from + j] = b
                    s[mid + j] = a
                }
            }
        }
    }
    sort(s1, 0, s1.size)
    sort(s2, 0, s2.size)
    println(if (String(s1) == String(s2)) "YES" else "NO")
}