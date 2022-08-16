for _ in range(int(input())):
	n,k1,k2 = map(int,input().split())
	a = list(map(int,input().split()))
	b = list(map(int,input().split()))
	if n in a:
		print("YES")
	else: print("NO")