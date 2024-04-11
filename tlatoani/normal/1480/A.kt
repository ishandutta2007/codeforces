fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val s = readLine()!!.toCharArray()
        for (j in s.indices) {
            s[j] = if (j % 2 == 0) {
                if (s[j] == 'a') 'b' else 'a'
            } else {
                if (s[j] == 'z') 'y' else 'z'
            }
        }
        println(s)
    }
}