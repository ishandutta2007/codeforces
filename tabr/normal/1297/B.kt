fun readln() = readLine()!!
fun readint() = readln().toInt() 
fun readlong() = readln().toLong() 
fun readdouble() = readln().toDouble()
fun readstrings() = readln().split(" ")
fun readints() = readstrings().map { it.toInt() } 
fun readlongs() = readstrings().map { it.toLong() } 
fun readdoubles() = readstrings().map { it.toDouble() }

fun main(){
	var tt = readint()
    while(tt-- > 0) {
        var n = readint()
        var a = IntArray(n)
        var b = IntArray(n)
        var st = mutableListOf<Int>()
        for(i in 0 until n) {
            var (x, y) = readints()
            a[i] = x
            b[i] = y
            st.add(x)
            st.add(y)
        }
        st.sort()
        var m = st.size
        fun check(z: Int): Boolean {
            var cnt = 0
            for(i in 0 until n) {
                if(cnt > 1){
                    return false
                }
                if(a[i] <= z && z <= b[i]) {
                    cnt++
                }
            }
            return (cnt == 1)
        }
        var ans = -1
        for(i in 0 until m) {
            if(check(st[i])) {
                ans = st[i]
                break
            }
            if(i != 0 && check((st[i - 1] + st[i]) / 2)) {
                ans = (st[i - 1] + st[i]) / 2
                break
            }
        }
        println(ans)
    }
}