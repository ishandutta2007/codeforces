fun main() {
    repeat(read()) {
        var s = readLine()!!
        var b = 0
        var m = 0
        for(i in 0 until s.length) {
            if(s[i] == '>') b= 1;
            if(s[i] == '<') m =1;
        }
        if(b==1 && m==1) println("?")
        else if(b==1) println(">")
        else if(m==1) println("<")
        else println("=")
    }
}

private fun read() = readLine()!!.toInt()
private fun readv() = readLine()!!.split(" ").map {it.toInt()}