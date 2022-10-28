r=range
n=int(input())
N=1<<n
s=input()
a=sorted([ord(s[i])*N+i for i in r(N)])
for j in r(n):
	p=1<<j;v=[0]*N;c=0;l=0
	for i in r(N):
		if a[i]//N>c:c=a[i]//N;l+=1
		v[a[i]%N]=l
	a=sorted([v[i]*N*N+v[i^p]*N+i for i in r(N)])
print(''.join([s[j^(a[0]%N)]for j in r(N)]))