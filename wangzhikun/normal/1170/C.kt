private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main(args: Array<String>) {
	var q = readInt()
	var s1:String
	var s2:String
	var ans = 0
	repeat(q){
		ans = 1
		s1 = readLn();
		s2 = readLn();
		var p = 0
		var p1 = 0
		while(p<s2.length){
			//println("$p1 $p");
			if(s1[p1] == s2[p]){
				p1+=1
				p+=1
				
			}else{
				
				if(p1 < s1.length-1 && s1[p1] == '-' && s2[p] == '+' && s1[p1+1] == '-'){
					p1+=2
					p+=1
				}else{
					ans = 0
				}
			}
			if(p == s2.length && p1 == s1.length)break;
			//println("233");
			if(p1>=s1.length){
				ans = 0
			}
			//println("233");
			if(ans == 0)break;
		}
		if(p1 != s1.length)ans = 0;
			
		if(ans == 1){
			println("YES")
		}else{
			println("NO")
		}
	}
}