fun main(args: Array<String>) {
val n = readLine()!!.toInt()
val a = readLine()!!.split(' ').map(String::toInt)
val m : MutableList<Int> = mutableListOf()
for(i in n-1 downTo 0){
m.add(a[i], i+1)
}
for(u in m){
print(u)
print(" ")
}
}