s = raw_input()
f = [0, 0, 0]
for i in s:
	if i == 'a':
		f[2] = max(f) + 1
		f[0] += 1
	else:
		f[1] = max(f[0], f[1]) + 1
print max(f)