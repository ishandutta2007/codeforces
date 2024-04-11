fun readln() = readLine()!!
fun readint() = readln().toInt() 
fun readlong() = readln().toLong() 
fun readdouble() = readln().toDouble()
fun readstrings() = readln().split(" ")
fun readints() = readstrings().map { it.toInt() } 
fun readlongs() = readstrings().map { it.toLong() } 
fun readdoubles() = readstrings().map { it.toDouble() }
var SZ=0

fun main() {
	var n=readint()
    var a=readints()
    var s = IntArray(n/2+1){-1}
    var t = IntArray(n/2+1){-1}
    var m=n/2
    for(i in 0 until n){
        if(a[i]>m)continue
        if(s[a[i]]==-1){
			s[a[i]]=i    
        }else if(t[a[i]]==-1){
            t[a[i]]=i
        }else{
            m=minOf(m,a[i]-1)
        }
    }
    for(i in 1..m){
        if(t[i]==-1){
            m=i-1
            break
        }
    }
    SZ=n+3
    val v = bit()
    val u = bit()
    for(i in 1..m){
        u.add(s[i]+1,1L)
        v.add(t[i]+1,1L)
        if(u.query(s[i]+1)!=v.query(t[i]+1)){
            m= i -1
            break
        }
    }
    var cnt=IntArray(m+1)
    var ans=CharArray(n){'B'}
    for(i in 0 until n){
      	if(a[i]>m)continue
        if(cnt[a[i]]==0){
            ans[i]='R'
            cnt[a[i]]++
        }else{
            ans[i]='G'
        }
    }
    println(ans)
}

class bit{
    val v=LongArray(SZ)
	fun add(_a: Int, b: Long) {
        var a = _a
        while (a < SZ) {
            v[a] += b
            a += (a and -a)
        }
    }
    fun query(_a: Int): Long {
        var a = _a
        var ans: Long = 0
        while (a > 0) {
            ans += v[a]
            a -= (a and -a)
        }
        return ans
    }
}