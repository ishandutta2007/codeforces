private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

fun main(){
	val t = readInt()
	for (i in 1..t){
		val n = readInt()
		val a = readInts()
		var li=0
		var ri=n-1
		var cnta=0
		var cntb=0
		var mv=0
		var lst = 0
		while(li <= ri){
			if(li <= ri){
				var sm = 0
				while(li <= ri && sm <= lst){
					sm += a[li++]
				}
				mv++
				cnta += sm
				lst = sm
			}
			if(li <= ri){
				var sm = 0
				while(li <= ri && sm <= lst){
					sm += a[ri--]
				}
				mv++
				cntb += sm
				lst = sm
			}
		}
		println("$mv $cnta $cntb")
	}
}