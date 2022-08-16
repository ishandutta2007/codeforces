n = int(input())
a = list(map(int,input().split()))
for i in a:
	x = i%14
	if x >= 1 and x <= 6 and i >= 15:
		print("YES")
	else:
		print("NO")