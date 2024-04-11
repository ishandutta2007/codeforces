fun main(args: Array<String>) {
    val t = readLine()!!.toInt()
    repeat(t) {
    	var x = readLine()!!.split("").sorted()
    	var ok = false
    	for(i in 2..((x.size)-2)){
        	if(x[i] != x[i+1]){
        		ok =true
        	}
        }
        if(ok){
        	var s = ""
        	for(i in 2..(x.size-1)){
        		s+=x[i]
        	}
        	println(s)
        }else{
        	println("-1")
        }
        
    }
}