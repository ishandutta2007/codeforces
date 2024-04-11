for _ in range(int(input())):
	x,y=map(int,input().split())
	print(x+y if x>y else y-(y%x)//2)