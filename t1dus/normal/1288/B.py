for _ in range(int(input())):
	a,b = map(int,input().split())
	cnt = 0
	x = 1
	while 1:
		x *= 10
		if x-1 <= b: cnt += 1
		else: break
	print(cnt*a)