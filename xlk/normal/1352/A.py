for t in range(int(input())):
	n = int(input())
	a = []
	for i in range(5):
		if n // 10 ** i % 10 > 0:
			a.append(n // 10 ** i % 10 * 10 ** i)
	print(len(a))
	print(*a)