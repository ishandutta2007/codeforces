c = 0
d = 0
n = input()
for i in range(2520):
	if i % 2 != 0 and i % 3 != 0 and i % 5 != 0 and i % 7 != 0:
		c += 1
		if i <= n % 2520:
			d += 1

print n / 2520 * c + d