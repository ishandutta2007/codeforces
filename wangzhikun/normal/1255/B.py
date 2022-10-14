for _ in range(int(input())):
	n,m = map(int,input().split())
	l = list(map(int,input().split()))
	if n>m or n==2:
		print (-1)
	else:
		print (sum(l)*2)
		for j in range(1,m):
			print(j,j+1)
		print (1,n)