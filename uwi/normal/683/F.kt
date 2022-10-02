import java.util.*

fun main(args: Array<String>) {
var line = readLine()!!.trim(' ').toLowerCase()
val reg = Regex(" +");
line = reg.replace(line, " ")
line = Regex("\\.(?! )").replace(line, ". ")
line = Regex(",(?! )").replace(line, ", ")
line = Regex(" ,").replace(line, ",")
line = Regex(" \\.").replace(line, ".")
line = line.trim(' ')
var first = true
for(s in line){
if(first && s >= 'a' && s <= 'z'){
print((s.toInt() - 'a'.toInt() + 'A'.toInt()).toChar())
}else{
print(s)
}
if(s != ' '){
if(s == '.'){
first = true
}else{
first = false
}
}
}
}