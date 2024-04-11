fun main(args: Array<String>) {
val a = readLine()!!.split(' ').map(String::toInt)
val b = readLine()!!.split(' ').map(String::toInt)
val aa:MutableList<Int> = mutableListOf()
val bb:MutableList<Int> = mutableListOf()
for(i in 1..a.size-1){
aa.add(a[i])
}
for(i in 1..b.size-1){
bb.add(b[i])
}
val ab = aa.subtract(bb)
val ba = bb.subtract(aa)
print(ab.size + ba.size)
print(" ")
for(i in ab){
print(i)
print(" ")
}
for(i in ba){
print(i)
print(" ")
}
}