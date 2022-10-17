n = input()
f = map(int, raw_input().split())
c = map(int, raw_input().split())
z = n
for i in range(n - 1):
	if c[i + 1] == c[f[i] - 1]:
		z -= 1
print z