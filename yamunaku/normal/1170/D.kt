fun main(){
    val n = readLine()!!.toInt()
    val v = readLine()!!.split(" ").map { it.toInt() }
    var num = 0
    for(x in v){
        if(x==-1) num++
    }
    var next=Array<Int>(num,{(it+1)%num})
    var pre=Array<Int>(num,{(it+num-1)%num})
    var ans=Array<ArrayList<Int>>(num, {ArrayList<Int>(0)})
    var idx = 0
    for(x in v){
        if(x==-1){
            next[pre[idx]] = next[idx]
            pre[next[idx]] = pre[idx]
        }else{
            ans[idx].add(x)
        }
        idx = next[idx]
    }
    println(num)
    for(i in 0..(num-1)){
        var x = ans[i].size
        print("$x")
        for(j in 0..(x-1)){
            var y = ans[i][j]
            print(" $y")
        }
        print("\n")
    }
}