I=lambda:[*map(int,input().split())]
n,m=I()
r=range
cells=[[]for i in r(100001)]
for i in r(n):
	x=I()
	for j in r(m):cells[x[j]].append((i, j))
cost=0
for i in r(100001):
	l=cells[i];x=len(l)
	for i in r(1,x):cost+=(l[i][0]-l[i-1][0])*i*(x-i)
	l.sort(key=lambda x:x[1])
	for i in r(1,x):cost+=(l[i][1]-l[i-1][1])*i*(x-i)
print(cost)