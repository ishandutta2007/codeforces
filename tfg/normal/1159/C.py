n, m = map(int, raw_input().split())

b = map(int, raw_input().split())
g = map(int, raw_input().split())


cont = 0
b.sort()
g.sort()
flag = True

for k in xrange(m):
	
	if b[-1] > g[k]:
		print -1
		exit()
	
	if b[-1] == g[k]:
		flag = False
	cont += g[k]
	
for k in xrange(n-1):
	cont += b[k]*m

if flag:
	cont -= (g[-1] - b[-1])
	cont -= b[n-2]
	cont += g[-1]

	

print cont