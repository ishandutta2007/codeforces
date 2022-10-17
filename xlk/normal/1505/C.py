s = input()
a = []
for i in s:
	a.append(ord(i) - ord('A'))
for i in range(2, len(s)):
	if a[i] != (a[i - 1] + a[i - 2]) % 26:
		print('NO')
		break
else:
	print('YES')