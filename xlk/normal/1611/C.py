for t in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	if a[0] == n:
		print(n, *a[1:][::-1])
	elif a[-1] == n:
		print(*a[:-1][::-1], n)
	else:
		print(-1)