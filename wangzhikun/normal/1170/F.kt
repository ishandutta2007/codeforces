private fun readLn() = readLine()!! // string line
private fun readLong() = readLn().toLong() // single Long
private fun readStrings() = readLn().split(" ") // list of strings
private fun readLongs() = readStrings().map { it.toLong() } // list of Longs

fun main(args: Array<String>) {
	var (n1,m1,k) = readLongs()
	var n = n1.toInt()
	var m = m1.toInt();
	var a = readLongs()
	var ra = mutableListOf(a[0])
	for(i in 1..n-1){
		ra.add(a[i])
	}
	ra.sort()
	var sa = mutableListOf(0,ra[0]);
	for(i in 1..n-1){
		sa.add(sa[sa.count()-1]+ra[i])
	}
	var ans:Long = 2000000000000000000
	for(st in 0..n-m){
		var l:Long = -1
		var r:Long = 1000000001
		var ecp = 0;
		while(l+1!=r){
			var mid = (l+r)/2
			var cp = ra.binarySearch(mid,st,st+m);
			ecp = cp;
			if(cp<0){
				cp = -(cp+1)-1;
			}
			var lad = mid*(cp-st+1)-(sa[cp+1]-sa[st])
			var req = (sa[st+m]-sa[cp+1])-mid*(st+m-1-cp);
			if(lad+req<ans && lad<=k){
				ans = lad+req;
			}

			if(lad>k || (cp-st+1)*2>=m){
				r = mid;
			}else{
				l = mid;
			}
		}
		
	}
	
	println("$ans");
	//println("233");
}