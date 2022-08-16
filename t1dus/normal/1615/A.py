for _ in range(int(input())):
	n = int(input())
	s = sum(list(map(int,input().split())))
	if(s%n == 0):
		print(0)
	else:
		print(1)