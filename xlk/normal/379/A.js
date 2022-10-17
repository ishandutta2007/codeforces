var l = readline().split(' ')
var a = +l[0], b = +l[1], z = a
for (; a >= b; ) {
	z += Math.floor(a / b)
	a = a % b + Math.floor(a / b)
}
print(z)