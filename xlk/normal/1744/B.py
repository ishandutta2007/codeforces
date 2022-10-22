t = int(input())
for tt in range(t):
	n, q = map(int, input().split())
	a = list(map(int, input().split()))
	e = [0, 0]
	for i in a:
		e[i % 2] += 1
	s = sum(a)
	for i in range(q):
		o, x = map(int, input().split())
		s += e[o] * x
		if x % 2:
			e[1 - o] += e[o]
			e[o] = 0
		print(s)