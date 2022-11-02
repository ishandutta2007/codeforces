import java.lang.StringBuilder

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readLong() = readLn().toLong()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLongs() = readStrings().map { it.toLong() }

fun main(){
	val T = readInt()
	for (t in 1..T){
		var (nn, k) = readLongs()
		val n = nn.toInt()
		val s = readLn()
		val res = ArrayList<Char>()
		var cnt = 0
		for(i in 0..n-1){
			if(s[i] == '0'){
				while(cnt > k){
					cnt--
					res.add('1')
				}
				k -= cnt
				res.add('0')
			}
			else{
				cnt++
			}
		}
		for(i in 1..cnt)
			res.add('1')
		val R = StringBuilder()
        for(c in res)
			R.append(c)
		println(R)
	}
}