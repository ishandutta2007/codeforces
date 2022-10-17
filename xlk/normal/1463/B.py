t = int(input())
for tt in range(t):
	n = int(input())
	a = list(map(int, input().split()))
	if sum(a[0::2]) < sum(a[1::2]):
		for i in range(0, n, 2):
			a[i] = 1
	else:
		for i in range(1, n, 2):
			a[i] = 1
	print(' '.join(map(str, a)))