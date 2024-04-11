fun main() {
    repeat(readLine()!!.toInt()) {
        readLine()!!
        println(readLine()!!.replace('D', '*').replace('U', 'D').replace('*', 'U'))
    }
}