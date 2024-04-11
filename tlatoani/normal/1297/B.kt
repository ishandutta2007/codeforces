fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val xs = mutableListOf<Int>()
        val cartoons = Array(n) {
            val line = readLine()!!
            val six = line.indexOf(' ')
            val a = line.substring(0, six).toInt()
            val b = line.substring(six + 1).toInt()
            xs.add(a)
            xs.add(b + 1)
            Pair(a, b)
        }
        var answer = -1
        for (x in xs) {
            var amt = 0
            for (cartoon in cartoons) {
                if (cartoon.first <= x && cartoon.second >= x) {
                    amt++
                }
            }
            if (amt == 1) {
                answer = x
                break
            }
        }
        println(answer)
    }
}