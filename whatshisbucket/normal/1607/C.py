t = int(input())
for _ in range(t):
	n = int(input())
	a = sorted(list(map(int, input().split())))
	shift = 0
	big = a[0]
	for guy in a:
		big = max(big, guy + shift)
		shift = -guy
	print(big)