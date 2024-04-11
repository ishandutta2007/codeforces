n = int(input())
for i in range(n):
	a,b,l,r = [int(i) for i in input().split(' ')]
	ans = (l-1) // b + a // b - r // b
	print(ans)