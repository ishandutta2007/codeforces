for _ in range(int(input())):
	n,g,b = map(int,input().split())
	orign = n
	n = (n+1)//2
	com = ((n-1)//g)
	ans = com*(g+b)
	n -= com*g
	ans += n
	print(max(ans,orign))