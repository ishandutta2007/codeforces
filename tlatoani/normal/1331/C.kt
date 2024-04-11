fun main() {
    var s = readLine()!!.toInt().toString(2)
    while (s.length < 6) {
        s = "0" + s
    }
    val builder = StringBuilder()
    builder.append(s[0]).append(s[5]).append(s[3]).append(s[2]).append(s[4]).append(s[1])
    println(builder.toString().toInt(2))
}