for _ in range(int(input())):
	a,b,c,r = map(int,input().split())
	if a > b: a,b = b,a
	x = max(c-r,a)
	y = min(c+r,b)
	ans = b-a
	ans -= max(0,y-x) 
	print(max(ans,0))