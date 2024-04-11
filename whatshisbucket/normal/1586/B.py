t=int(input())
for _ in range(t):
	n,m=map(int,input().split())
	appearances = [0]*n
	for i in range(m):
		a,b,c=map(int,input().split())
		appearances[b-1]=1
	for i in range(n):
		if appearances[i] == 0:
			for j in range(n):
				if j!=i:
					print(i+1,j+1)
			break