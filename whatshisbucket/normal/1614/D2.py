import collections as C
N=20000001;c,e,P,v,d=C.Counter(list(map(int,[*open(0)][1].split()))),[0]*N,[0],[0]*N,[0]*N
for i in range(2,N):
	if e[i]<1:
		P.append(i);j=i
		while j<N:e[j]=i;j+=i
def f(n):
	s=[1]
	while n>1:
		p,c,w=e[n],1,[]
		while e[n]==p:c+=1;n//=p
		for g in s:
			for i in range(c):w.append(g*p**i)
		s=w
	return s
for i in c:
	for j in f(i):v[j]+=c[i]
i=N
while i>1:
	i-=1
	if v[i]>0:
		for p in P:
			if p*i>=N:break
			d[i]=max(d[i],d[p*i]+i*(v[i]-v[p*i]))
print(d[1])