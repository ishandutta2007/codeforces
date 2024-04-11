fun main(args: Array<String>) {
var line = readLine()!!.split(Regex("[\\(\\)]"))
var den : Long = 0
var num = line[1].toLong()
for(i in 1..line[1].length){
den = den * 10 + 9
}
var dot = false
for(j in line[0].length-1 downTo 0){
if(line[0][j] == '.'){
dot = true
continue
}
var o = line[0][j].toInt()-'0'.toInt()
num = num + den * o
if(!dot){
 den = den * 10
}
}
var a = num
var b = den
while(b > 0){
var c = a
a = b
b = c % b
}
num = num / a
den = den / a
print(num)
print("/")
println(den)

}