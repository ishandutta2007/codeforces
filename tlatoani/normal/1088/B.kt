fun main() {
    var k = readLine()!!.substringAfter(' ').toInt()
    val numbers = readLine()!!.split(" ").map { it.toInt() }.sorted()
    val out = StringBuilder()
    var prev = 0
    for (number in numbers) {
        if (number > prev) {
            out.appendln(number - prev)
            prev = number
            k--
            if (k == 0) {
                break
            }
        }
    }
    while (k > 0) {
        out.appendln(0)
        k--
    }
    print(out)
}