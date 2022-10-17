n,m,k=map(int,raw_input().split())
w=[1E7]*m
for i in range(n):
	x,y=map(int,raw_input().split())
	w[x-1]=min(w[x-1],y)
print min(sum(w),k)