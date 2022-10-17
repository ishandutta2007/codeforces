t = int(input())
for tt in range(t):
	n = int(input())
	z = 0
	i = 1
	while True:
		if n >= i * (2 * i - 1):
			n -= i * (2 * i - 1)
			z += 1
			i *= 2
		else:
			break
	print(z)