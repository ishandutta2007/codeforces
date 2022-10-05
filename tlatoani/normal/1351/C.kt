fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val visitedNorth = mutableSetOf<Pair<Int, Int>>()
        val visitedEast = mutableSetOf<Pair<Int, Int>>()
        var answer = 0
        var x = 0
        var y = 0
        for (chara in readLine()!!) {
            when (chara) {
                'N' -> {
                    if (visitedNorth.add(Pair(x, y))) {
                        answer += 5
                    } else {
                        answer++
                    }
                    y++
                }
                'S' -> {
                    y--
                    if (visitedNorth.add(Pair(x, y))) {
                        answer += 5
                    } else {
                        answer++
                    }
                }
                'E' -> {
                    if (visitedEast.add(Pair(x, y))) {
                        answer += 5
                    } else {
                        answer++
                    }
                    x++
                }
                'W' -> {
                    x--
                    if (visitedEast.add(Pair(x, y))) {
                        answer += 5
                    } else {
                        answer++
                    }
                }
            }
        }
        println(answer)
    }
}