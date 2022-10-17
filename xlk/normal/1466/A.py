t = int(input())
for tt in range(t):
	n = int(input())
	a = list(map(int, input().split()))
	s = set()
	for i in a:
		for j in a:
			if i > j:
				s.add(i - j)
	print(len(s))