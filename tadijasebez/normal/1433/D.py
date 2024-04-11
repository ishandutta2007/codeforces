t = int(input())
for tc in range(t):
	n = int(input())
	a = list(map(int, input().split()))
	b = [i for i in range(1,n) if a[i]!=a[0]]
	if len(b)==0:
		print("NO")
	else:
		print("YES")
		for i in range(1,n):
			print(i+1, 1 if a[i]!=a[0] else b[0]+1)