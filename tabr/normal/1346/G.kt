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
    var(k,n)=readints()
    var p=readints()
    var x=readints()
    if(n==2){
        println("YES")
        println("${x[0]} ${p[0]}")
        println("${x[1]} ${p[0]}")
        p[k-1]
        return
    }
    var ok=false
    var lst=listOf(x[1]-x[0],x[2]-x[0],x[2]-x[1])
    var beg=listOf(0,0,1)
    var st=p.toHashSet()
    var s0=0
    var s1=0
    var c0=0
    var c1=0
    for(idd in 0..2){
        var kouho=mutableListOf<Int>()
        for(j in 1..lst[idd]){
            if(j*j>lst[idd]){
                break
            }
            if(lst[idd]%j==0){
                if(st.contains(j)){
                    kouho.add(j)
                }
                if(j*j!=lst[idd]&& st.contains(lst[idd]/j)){
                    kouho.add(lst[idd]/j)
                }
            }
        }
        for(t in kouho){
            var b=IntArray(n)
            for(i in 0..n-1){
                if(i>=beg[idd]&&(x[i]-x[beg[idd]])%t==0){
                    b[i]=1
                }
            }
            var id=-1
            for(i in 0..n-1){
                if(b[i]==0){
                    id=i
                    break
                }
            }
            if(id==-1){
                c0=t
                c1=t
                s0=x[beg[idd]]
                s1=x[beg[idd]]
                ok=true
                break
            }
            var g=0
            for(i in id+1..n-1){
                if(b[i]==0){
                    g=gcd(g,x[i]-x[id])
                }
            }
            if(g==0){
                ok=true
                c0=t
                c1=t
                s0=x[beg[idd]]
                s1=x[id]
                break
            }
            for(j in 1..g){
                if(j*j>g){
                    break
                }
                if(g%j==0){
                    if(st.contains(j)){
                        ok=true
                        c0=t
                        c1=j
                        s0=x[beg[idd]]
                        s1=x[id]
                        break
                    }
                    if(j*j!=g && st.contains(g/j)){
                        ok=true
                        c0=t
                        c1=g/j
                        s0=x[beg[idd]]
                        s1=x[id]
                    }
                }
            }
            if(ok){
                break
            }
        }
        if(ok){
            break
        }
    }
    if(ok){
        println("YES")
        println("${s0} ${c0}")
        println("${s1} ${c1}")
    }else{
        println("NO")
    }
}  

fun gcd(a: Int, b: Int): Int {
    if(b == 0) return a
    return gcd(b, a % b)
}