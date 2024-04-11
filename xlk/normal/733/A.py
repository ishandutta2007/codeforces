s = raw_input()
s = 'A' + s + 'A'
z = 0
l = 0
for i in s:
	if i in 'AEIOUY':
		l = 1
	else:
		l += 1
	z = max(l, z)
print z