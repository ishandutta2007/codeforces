def F(s):
	z = 0
	for i in s:
		z += ord(i) - 96
	return z
for t in range(int(input())):
	s = input()
	if len(s) & 1:
		d = max(F(s[1:]) - F(s[:1]), F(s[:-1]) - F(s[-1:]))
		if d > 0:
			print('Alice', d)
		else:
			print('Bob', -d)
	else:
		print('Alice', F(s))