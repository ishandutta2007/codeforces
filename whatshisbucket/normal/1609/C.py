import sys
inpu = sys.stdin.readline
prin = sys.stdout.write

e = [0]*1000000
P = []
for i in range(2,1000000):
	if e[i]<1:
		P.append(i);j=i
		while j<1000000:e[j]=i;j+=i
P=set(P)
t = int(inpu())
for _ in range(t):
	n, e = map(int, inpu().split())
	a = list(map(int, inpu().split()))
	broken = [[] for i in range(e)]
	for i in range(n):
		broken[i % e].append(a[i])
	tot = 0
	for i in range(e):
		l = broken[i]
		prev = 0
		curr = 0
		prime = False
		for j in range(len(l)):
			if l[j] == 1:
				if prime:
					tot += prev + 1
				curr += 1
			elif l[j] in P:
				prev = curr
				curr = 0
				tot += prev
				prime = True
			else:
				prev = 0
				curr = 0
				prime = False
	print(tot)