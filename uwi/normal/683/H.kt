fun main(args: Array<String>) {
val sp = readLine()!!.split(" ")
val n = sp[0].toInt()
val k = sp[1].toLong()
val ved : MutableList<Int> = mutableListOf()
var f = readLine()!!.split(" ").map{x -> x.toInt()-1}
val last : MutableList<Int> = mutableListOf()
for(i in 0..n-1){
last.add(-1)
ved.add(0)
}
for(i in 0..n-1){
if(ved[i] == 1){
continue
}
var cyc : MutableList<Int> = mutableListOf()
var cur = i
while(ved[cur] == 0){
cyc.add(cur)
ved[cur] = 1
cur = f[cur]
}
var d = (k % cyc.size).toInt()
for(j in 0..cyc.size-1){
last[cyc[d]] = cyc[j]
d += 1
if(d == cyc.size){
d = 0
}
}
}
for(i in 0..n-1){
print(last[i]+1)
print(" ")
}
}