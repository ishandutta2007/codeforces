fun main(){
    val n = readLine()!!.toInt()
    for(t in 1..n){
        val s = readLine()!!
        val t = readLine()!!
        var i = 0
        var j = 0
        var ok:Boolean = true
        while(i<s.length&&j<t.length) {
            if (t[j] == '+') {
                if (s[i] == '+') {
                    i++
                    j++
                } else {
                    if (i < s.length - 1) {
                        if (s[i] == '-' && s[i + 1] == '-') {
                            i += 2
                            j++
                        } else {
                            ok = false;
                            break;
                        }
                    } else {
                        ok = false;
                        break;
                    }
                }
            } else {
                if (s[i] != '-') {
                    ok = false;
                    break;
                }
                i++
                j++
            }
        }
        if(ok&&i==s.length&&j==t.length) println("YES")
        else println("NO")
    }
}