fun main(){
    val nm = readLine()!!.split(" ").map { it.toInt() }
    val n = nm[0]
    val m = nm[1]
    val a = readLine()!!.split(" ").map { it.toInt() }
    var rui = Array<Int>(n+1,{0})
    rui[0]=0;
    for(i in 1..n) rui[i]=a[i-1]+rui[i-1]
    val q = readLine()!!.toInt()
    for(t in 1..q){
        val v = readLine()!!.split(" ").map { it.toInt() }
        var pos = 0
        var idx = 0
        for(i in 1..v[0]){
            var l = idx
            var r = n+1
            var mid = 0
            while(r-l>1){
                mid = (l+r)/2
                if(pos+rui[mid]-rui[idx]<v[i]){
                    l = mid
                }else{
                    r = mid
                }
            }
            pos = v[i]
            idx = l
        }
        if(pos+rui[n]-rui[idx]<=m) println("YES")
        else println("NO")
    }
}