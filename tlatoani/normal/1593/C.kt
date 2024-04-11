fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, k) = readLine()!!.split(" ").map { it.toInt() }
        var answer = 0
        var sum = 0
        for (x in readLine()!!.split(" ").map { it.toInt() }.sortedDescending()) {
            if (sum + (n - x) >= n) {
                break
            }
            answer++
            sum += n - x
        }
        println(answer)
    }
}