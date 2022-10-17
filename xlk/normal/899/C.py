n = input()
print n * (n + 1) / 2 % 2, n / 2
for i in range(n / 2):
	print n - 2 * i - i % 2,