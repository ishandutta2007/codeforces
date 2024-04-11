import sys
input = sys.stdin.readline
I = lambda : list(map(int,input().split()))
 
t,=I()
for _ in range(t):
	n,=I()
	l=I()
	deg=[0]*n
	for i in range(n-1):
		u,v=I()
		deg[u-1]+=1
		deg[v-1]+=1
	ar=[]
	for i in range(n):
		if len(ar)<n:
			ar+=[l[i]]*(deg[i]-1)
	ar.sort(reverse=True)
	an=[sum(l)]
	for i in range(n-2):
		an.append(an[-1]+ar[i])
	print(*an)