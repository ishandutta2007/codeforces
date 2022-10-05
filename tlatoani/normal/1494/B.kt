fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val (n, u, r, d, l) = readLine()!!.split(" ").map { it.toInt() }
        var answer = "nO"
        for (ul in 0..1) {
            for (dl in 0..1) {
                for (dr in 0..1) {
                    for (ur in 0..1) {
                        if (u - ur - ul in 0..n - 2 && l - ul - dl in 0..n - 2 && d - dl - dr in 0..n - 2 && r - dr - ur in 0..n - 2) {
                            answer = "yEs"
                        }
                    }
                }
            }
        }
        println(answer)
    }
}