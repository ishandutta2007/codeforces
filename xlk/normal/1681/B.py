for tt in range(int(input())):
	input()
	a = list(map(int, input().split()))
	input()
	b = list(map(int, input().split()))
	print(a[sum(b) % len(a)])