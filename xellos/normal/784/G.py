expr = input()
val = eval(expr)
prog = ''
vald = []
if val == 0: vald.append(0)
else:
	while val:
		vald.append(val%10)
		val = val//10
	for i in range(len(vald)//2):
		vald[i], vald[len(vald)-1-i] = vald[len(vald)-1-i], vald[i]
for x in vald:
	prog += '[-]'
	for i in range(x+ord('0')): prog += '+'
	prog += '.'
print(prog)