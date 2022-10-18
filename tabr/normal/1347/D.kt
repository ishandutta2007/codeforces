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
        var n=readint()
        var a = readints()
        var aid=0
        var bid=n-1
        var alast = 0
        var blast = 0
        var ans=IntArray(3)
        if(alast<blast)aid++
        while(aid<=bid){
            ans[0]++
            var tmp=0
            while(tmp<=blast&&aid<=bid){
                tmp+=a[aid]
                aid++
            }
            alast=tmp
            ans[1]+=alast
            if(bid<aid){
                break
            }
            ans[0]++
            tmp=0
            while(tmp<=alast&&aid<=bid){
                tmp+=a[bid]
                bid--
            }
            blast=tmp
            ans[2]+=blast
        }
        println(ans.joinToString(" "))
    }
}