fun main() {
    val out = StringBuilder()
    repeat(readLine()!!.toInt()) {
        val numbers = readLine()!!.map { it - 'a' }
        val freq = IntArray(26)
        val toUse = mutableListOf<Int>()
        for (j in numbers.indices) {
            if (freq[numbers[j]] < 2) {
                freq[numbers[j]]++
                toUse.add(j)
            }
        }
        toUse.sortBy { numbers[it] }
        while (toUse.size % 2 != 0) {
            toUse.removeAt(toUse.lastIndex)
        }
        out.appendln(toUse.size / 2)
    }
    print(out)
}