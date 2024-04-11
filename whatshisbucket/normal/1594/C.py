t = int(input())
for i in range(t):
	a = input().split()
	n = int(a[0])
	c = a[1]
	s = input()
	if s == c*n:
		print(0)
	else:
		done = False
		for i in range(n):
			if s[-1-i] == c and i < n/2:
				print(1)
				print(n-i)
				done = True
				break
		if not done:
			print(2)
			print(n, n-1)