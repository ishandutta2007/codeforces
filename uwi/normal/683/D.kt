fun main(args: Array<String>) {
val q = readLine()!!.toInt()
for(i in 1..q){
val (n,m,p) = readLine()!!.split(' ').map(String::toInt)
var ok = false
for(u in 1..p){
if(p % u == 0 && u <= n && p/u <= m){
println("Yes")
ok = true
break
}
}
if(!ok){
println("No")
}
}
}