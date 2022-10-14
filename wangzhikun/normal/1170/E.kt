private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main(args: Array<String>) {
	var (n,m) = readInts();
	var a = readInts();
	var sa = mutableListOf<Int>()
	sa.add(0);
	for(i in 0..n-1){
		sa.add(sa[sa.count()-1]+a[i]);
	}

	var q = readInt()
	repeat(q){
		var cq = readInts()
		var ans = 1
		var cp1 = 0
		var cp2 = 0
		for(i in 1..cq[0]){
			var cpo = sa.binarySearch(sa[cp1]+cq[i]-cp2-1);
			//println("$cpo")
			if(cpo<0){
				cpo = -(cpo+1)-1;
			}
			if(cpo>cp1)cp1 = cpo;
			cp2 = cq[i];
			//println("$cp1 $cp2 ${cq[i]}")
		}
		//println("$cp1 $cp2 ${sa[sa.count()-1]-sa[cp1]}")
		if(sa[sa.count()-1]-sa[cp1]<=m-cp2){
			println("YES");
		}else{
			println("NO");
		}
	}
}