fun main() {
    for (c in 1..readLine()!!.toInt()) {
        var answer = -1
        var curr = 0
        for (chara in readLine()!! + "w") {
            if (chara == 'v') {
                curr++
            } else {
                answer += curr / 2
                curr = 0
                answer++
            }
        }
        println(answer)
    }
}