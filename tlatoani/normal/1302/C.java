fun main() {
    val s = "K" + readLine()!! + "V"
    var answer = 0
    var addend = 0
    for (j in 0..s.length - 2) {
        if (s.substring(j, j + 2) == "VK") {
            answer++
        }
        if (j <= s.length - 3 && (s.substring(j, j + 3) == "VVV" || s.substring(j, j + 3) == ("K" + "KK"))) {
            addend = 1
        }
    }
    println(answer + addend)
}