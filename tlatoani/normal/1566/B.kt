fun main() {
    repeat(readLine()!!.toInt()) {
        val s = readLine()!!
        if ('0' in s) {
            val j = s.indexOf('0')
            val k = s.lastIndexOf('0')
            if ('1' !in s.substring(j, k + 1)) {
                println(1)
            } else {
                println(2)
            }
        } else {
            println(0)
        }
    }
}