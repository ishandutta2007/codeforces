private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

fun gcd(a2:Int, b2:Int) : Int {
	var tmp : Int
	var a = a2
	var b = b2
	while(b > 0) {
		a %= b
		tmp = a
		a = b
		b = tmp
	}
	return a
}

fun main(){
	val (k, n) = readInts()
	val P = readInts()
	val X = readInts()
	if(n <= 2){
		println("YES")
		println("${X[0]} ${P[0]}\n${X[1]} ${P[0]}")
		return
	}
	for((a,b) in listOf(listOf(0,1),listOf(0,2),listOf(1,2))){
		for(p in P){
			if((X[b]-X[a])%p == 0){
				var fst = -1
				var lst = -1
				var dv = -1
				for(x in X){
					if((x-X[a])%p != 0){
						if(fst == -1){
							fst = x
						}
						else{
							if(dv == -1)
								dv = x-lst
							else
								dv = gcd(dv, x-lst)
						}
						lst = x
					}
				}
				if(fst == -1){
					println("YES")
					println("${X[a]} $p\n1 ${P[0]}")
					return
				}
				else if(dv == -1){
					println("YES")
					println("${X[a]} $p\n$fst ${P[0]}")
					return
				}
				else{
					for(p2 in P){
						if(dv % p2 == 0){
							println("YES")
							println("${X[a]} $p\n$fst $p2")
							return
						}
					}
				}
			}
		}
	}
	println("NO")
}