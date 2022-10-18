import java.util.*
fun readln() = readLine()!!
fun readint() = readln().toInt()
fun readlong() = readln().toLong()
fun readdouble() = readln().toDouble()
fun readstrings() = readln().split(" ")
fun readints() = readstrings().map { it.toInt() }
fun readlongs() = readstrings().map { it.toLong() }
fun readdoubles() = readstrings().map { it.toDouble() }

fun main() {
    var tt = readint()
    while (tt-- > 0) {
        var (n,m)=readints()
        var a=Array<String>(n){""}
        for(i in 0..n-1){
            a[i]=readln()
        }
        var ans="-1"
        for(i in 0..m-1){
            for(j in 0..25){
                var c = 'a'+j
                var s=""
                for(t in 0..m-1){
                    if(t==i){
                        s+=c
                    }else{
                        s+=a[0][t]
                    }
                }
                var ok=true
                for(k in 0..n-1){
                    var dif=0
                    for(l in 0..m-1){
                        if(s[l]!=a[k][l]){
                            dif++
                        }
                    }
                    if(dif>1){
                        ok=false
                    }
                }
                if(ok){
                    ans=s
                    break
                }
                if(ans!="-1")break
            }
            if(ans!="-1")break
        }
        println(ans)
    }
}

// kotlin sol.jar<in>out