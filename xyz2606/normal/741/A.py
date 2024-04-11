def gcd(a, b) :
	return a if b == 0 else gcd(b, a % b)
n = input()

a = map(eval, raw_input().split())
indeg = []
for i in range(n) :
	a[i] -= 1
	indeg = indeg + [0]
for i in range(n) :
	indeg[a[i]] += 1
for i in range(n) :
	if indeg[i] != 1 :
		print -1
		exit()
ans = 1
for i in range(n) :
	l = 1
	x = a[i]
	while x != i :
		l = l + 1
		x = a[x]
	if l % 2 == 0 :
		l /= 2
	ans = ans * l / gcd(ans, l)
print ans