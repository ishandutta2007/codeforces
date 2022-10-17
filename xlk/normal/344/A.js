var n = readline()
var q = "", z = 0
for (var i = 0; i < n; i++) {
	var s = readline()
	if (s != q) {
		q = s
		z++
	}
}
print(z)