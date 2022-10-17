n = input()
def F(n):
	if n == 0:
		return 0
	return F(n / 10) + n % 10
z = []
for i in range(min(99, n)):
	if F(n - i) == i:
		z.append(n - i)
print len(z)
for i in z[::-1]:
	print i