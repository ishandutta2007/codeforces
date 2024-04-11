fun main() {
    repeat(read()) {
        var n = read()
        var s = readLine()!!
        var t = readLine()!!
        var fix = Array(n, {0})
        var blink = Array(n, {0})
        for(i in 0 until n-3) {
            if(t[i] == '1') {
                fix[i] = 1
                fix[i+3] = -1
                blink[i+1] = 1
            }
        }
        var can = 1
        for(i in 0..n-1) {
            if(fix[i] != 0 && blink[i] == 1) {
                if(fix[i+1] == fix[i]) can = 0
                fix[i+1] = -fix[i]
            }
        }
        for(irev in 1 until n ) {
            val i = n-1-irev
//            println("  $i")
            if(fix[i+1] != 0 && blink[i] == 1) {
                if(fix[i+1] == fix[i]) can = 0
                fix[i] = -fix[i+1]
            }
        }
        if(can == 0) println("-1")
        else {
            var ans = 0
            for(i in 0 until n) {
                if(fix[i] != 0) {
                    if(fix[i] == -1 && s[i] == '(') ans++
                    if(fix[i] == 1 && s[i] == ')') ans++
                }
            }
            var l = 0
            while(l<n) {
                if(fix[l] != 0 || blink[l] == 0) l++
                else {
                    var r = l+1
                    while(r<n && blink[r] == 1) r++
                    var t1 = 0
                    var t2 = 0
                    for(i in l until r+1) {
                        if(i%2 == 0) {
                            if(s[i] == '(') t1++;
                            else t2++;
                        }
                        else {
                            if(s[i] == ')') t1++;
                            else t2++;
                        }
                    }
                    ans += minOf(t1,t2)
                    l = r
                }
            }
            println(ans)
        }

    }
}

private fun read() = readLine()!!.toInt()
private fun readv() = readLine()!!.split(" ").map {it.toInt()}