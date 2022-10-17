a = [0, 1, 3, 7, 12, 20, 30, 44, 65, 80, 96, 122, 147, 181, 203, 251, 289, 360, 400, 474]
n = input()
for i in range(n):
	for j in range(n):
		if i == j:
			print 0,
		else:
			print a[i] + a[j],
	print