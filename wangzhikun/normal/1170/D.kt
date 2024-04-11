private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main(args: Array<String>) {
	var m = readInt()
	var n = readInts()
	var nxt = Array(300030){0}
	var al = Array(300030){mutableListOf<Int>()}
	var cnt = 0
	var id = 0
	while(id<m){
		if(n[id] == -1){
			cnt+=1
		}
		id = id+1
	}
	id = 1
	while(id<cnt){
		nxt[id] = id+1
		id+=1
	}
	nxt[cnt] = 1
	var cp = cnt
	id = 0
	while(id<m){
		//println("${nxt[1]} ${nxt[2]} ${nxt[3]} $cp ${n[id]}")
		if(n[id] == -1){
			nxt[cp] = nxt[nxt[cp]];
		}else{
			al[nxt[cp]].add(n[id])
		}
		if(n[id] != -1)cp = nxt[cp]
		
		id = id+1
	}
	println("$cnt")
	for(i in 1..cnt){
		print("${al[i].count()} ");
		for(j in al[i]){
			print("$j ");
		}
		print("\n");
	}
}