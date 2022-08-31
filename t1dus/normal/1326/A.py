for _ in range(int(input())):
	n = int(input())
	if(n == 1): print(-1)
	elif(n%3 != 1):
		print("2"*(n-1)+"3")
	else:
		print("2"*(n-2)+"43")