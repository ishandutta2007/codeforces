n = input()
v = [0] * (n + 1)
p = n
z = 1
print z,
for i in map(int, raw_input().split()):
	z += 1
	v[i] = 1
	while v[p]:
		p -= 1
		z -= 1
	print z,