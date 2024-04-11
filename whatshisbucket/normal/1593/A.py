t=int(input())
for _ in range(t):
	a,b,c=map(int,input().split())
	print(max(a,max(b,c)+1)-a,max(b,max(a,c)+1)-b,max(c,max(a,b)+1)-c)