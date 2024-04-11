fun main(args: Array<String>) {
val n = readLine()!!.toInt()
val numbers: MutableList<Pair<Int,String>> = mutableListOf()
for(i in 0..n-1){
val ws = readLine()!!.split(' ')
val x = ws[0]
val y = ws[1]
val z = y.toInt()
numbers.add(Pair(z,x))
}
numbers.sortBy{x -> x.first}
for(p in numbers){
println(p.second)
}
}