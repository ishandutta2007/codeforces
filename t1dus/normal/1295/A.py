for _ in range(int(input())):
	n = int(input())
	if(n%2):
		print("7"+"1"*((n-3)//2))
	else:
		print("1"*(n//2))