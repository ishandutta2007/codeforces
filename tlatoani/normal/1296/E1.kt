fun main() {
    val n = readLine()!!.toInt()
    val s = readLine()!!
    var k = 0
    val answer = IntArray(n)
    val colors = IntArray(26)
    for (j in 0 until n) {
        val chara = s[j] - 'a'
        var color = 0
        for (b in chara downTo 0) {
            if (colors[b] != 0) {
                color = colors[b]
                colors[b] = 0
                break
            }
        }
        if (color == 0) {
            k++
            color = k
        }
        colors[chara] = color
        answer[j] = color
    }
    if (k > 2) {
        println("NO")
    } else {
        println("YES")
        println(answer.map { it % 2 }.joinToString(""))
    }
}