fun main(args : Array<String>) {
	//var (a, x, y) = readLine()!!.split(' ').map(String::toInt)
	var s = readLine()!!.toLowerCase().replace(",", ", ").replace(".", ". ")
	s = s.replace(Regex(" +"), " ")
	s = s.replace(" ,", ",")
	s = s.replace(" .", ".").trim()
	var ca = true
	for(c2 in s) {
		var c = c2
		if(ca && c >= 'a' && c <= 'z') {
			c = c.toUpperCase()
			ca = false
		}
		print(c)
		if(c == '.') ca = true
	}
	println("")
}