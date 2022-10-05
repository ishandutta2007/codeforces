fun main() {
    repeat(readLine()!!.toInt()) {
        readLine()
        val a = readLine()!!
        val b = readLine()!!
        if (a.endsWith(b.substring(1)) && b[0] in a.substring(0, a.length - (b.length - 1))) {
            println("yEs")
        } else {
            println("nO")
        }
    }
}