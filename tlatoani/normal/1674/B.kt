fun main() {
    val dictionary = mutableListOf<String>()
    for (a in 'a'..'z') {
        for (b in 'a'..'z') {
            if (b != a) {
                dictionary.add(a + "" + b)
            }
        }
    }
    repeat(readLine()!!.toInt()) {
        val s = readLine()!!
        println(dictionary.indexOf(s) + 1)
    }
}