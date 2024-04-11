fun main() {
    while (true) {
        println("next 0 1")
        readLine()
        println("next 1")
        val groups = readLine()!!.substring(2)
        if (groups.indexOf('0') + 1 == groups.indexOf('1')) {
            break
        }
    }
    while (true) {
        println("next 0 1 2 3 4 5 6 7 8 9")
        val groups = readLine()!!.substring(2)
        if (groups.indexOf('1') + 1 == groups.indexOf('2')) {
            println("done")
            return
        }
    }
}