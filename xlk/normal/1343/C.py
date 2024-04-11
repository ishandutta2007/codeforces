t = int(input())
for tt in range(t):
	n = int(input())
	a = list(map(int, input().split()))
	s = a[0]
	l = a[0]
	for i in range(1, n):
		if a[i] > 0 and l < 0 or a[i] < 0 and l > 0:
			l = a[i]
			s += l
		elif l < a[i]:
			s += a[i] - l
			l = a[i]
	print(s)