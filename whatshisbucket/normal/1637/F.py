import sys
I=lambda:[*map(int,sys.stdin.readline().split())]
import heapq as H
r=range
n,=I()
h=I()
g=[[] for i in r(n)]
for i in r(n-1):u,v=I();g[u-1].append(v-1);g[v-1].append(u-1)
u=[len(g[i])for i in r(n)]
t=[0]*n
q=[]
for i in r(n):
	if u[i]==1:H.heappush(q,(h[i],i))
c=0
while 1:
	_,v=H.heappop(q);x=[t[w]for w in g[v]];x.append(0);x.sort()
	if u[v]==0:c+=2*_-x[-1]-x[-2];break
	else:
		t[v]=max(_,x[-1]);c+=t[v]-x[-1]
		for x in g[v]:
			u[x]-=1
			if u[x]==1:H.heappush(q,(h[x], x))
print(c)