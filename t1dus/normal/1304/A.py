for _ in range(int(input())):
	x,y,a,b = map(int,input().split())
	y -= x
	x = 0
	ans = y/(a+b)
	if int(ans) == ans: print(int(ans))
	else: print(-1)