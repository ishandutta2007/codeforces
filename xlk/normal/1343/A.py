t = int(input())
for tt in range(t):
	n = int(input())
	k = 3
	while n % k > 0:
		k = k * 2 + 1
	print(n // k)