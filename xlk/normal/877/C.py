n = input()
z = range(1, n, 2) + range(0, n, 2) + range(1, n, 2)
print len(z)
for i in z:
	print i + 1,