fun main() {
    repeat(read()) {
        var n =read()
        var mn = 0
        var mx = 500500
        repeat(n) {
            var s = readLine()!!.split(" ")
            var a = s[0]
            var b = s[1]
            var c = s[2].toInt()
            var cur = minOf(a.length, b.length)
            for(i in 0 until minOf(a.length, b.length)) {
                if(a[a.length - 1 - i] != b[b.length -1 -i]) {
                    cur = i
                    break
                }
            }
            if(c == 1) mx = minOf(mx, cur)
            if(c==0) mn = maxOf(mn, cur+1)
        }
        mx = maxOf(mx, mn-1)
        println(mx-mn+1)
        for (i in mn until mx) print("$i ")
        if(mx>=mn) print("$mx")
        println()
    }
}

private fun read() = readLine()!!.toInt()
private fun readv() = readLine()!!.split(" ").map {it.toInt()}