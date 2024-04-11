import sys
I = lambda: [*map(int, sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, = I()
	a = []
	for i in range(n):
		a.append(sys.stdin.readline().strip())

	seen = set()
	other = set()
	for guy in a:
		if len(guy) == 1:
			print('YES')
			break
		if len(guy) == 2:
			if guy[0] == guy[1]:
				print('YES')
				break
			if guy[::-1] in seen or guy[::-1] in other:
				print('YES')
				break
			seen.add(guy)
		if len(guy) == 3:
			if guy[0] == guy[2]:
				print('YES')
				break
			if guy[::-1] in seen or guy[2:0:-1] in seen:
				print('YES')
				break
			seen.add(guy)
			other.add(guy[:2])
	else:
		print('NO')