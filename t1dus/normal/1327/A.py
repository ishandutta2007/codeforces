for _ in range(int(input())):
	n,k = map(int,input().split())
	if(n >= k*k and n%2 == (k*k)%2):
		print("YES")
	else:
		print("NO")