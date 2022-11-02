n,k=map(int,raw_input().split())
a=map(int,raw_input().split())
Max=0
ans=0
for i in range(n):
	if (a[i]+k-1)/k>=Max:
		Max=(a[i]+k-1)/k
		ans=i
print ans+1