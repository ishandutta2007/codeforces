n,m=map(int,raw_input().split())
m%=n*(n+1)/2
for i in range(n):
	if m<i:
		break
	m-=i
print m