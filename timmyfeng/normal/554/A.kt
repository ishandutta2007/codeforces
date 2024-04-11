fun main() {
    val s = readLine()!!

    val span = mutableSetOf<String>()
    for (i in 0..s.length) {
        for (j in 'a'..'z') {
            span.add(s.substring(0, i) + j + s.substring(i))
        }
    }

    println(span.size)
}