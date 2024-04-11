import sys
inpu = sys.stdin.readline
prin = sys.stdout.write

t = int(inpu())
for _ in range(t):
	n, a, b = map(int, inpu().split())
	if abs(a - b) > 1 or a + b > n - 2:
		print(-1)
		continue
	out = []
	if a == b:
		for i in range(a):
			out.append(i + 1)
			out.append(i + a + 2)
		out.append(a + 1)
		while len(out) < n:
			out.append(len(out) + 1)
	elif a < b:
		for i in range(b):
			out.append(i + b + 1)
			out.append(i + 1)
		while len(out) < n:
			out.append(len(out) + 1)
	else:
		for i in range(b):
			out.append(i + 1)
			out.append(i + b + 2)
		out.append(b + 1)
		out.append(n)
		while len(out) < n:
			out.append(out[-1] - 1)
	print(' '.join(str(guy) for guy in out))