import sys
inpu=sys.stdin.readline
prin=sys.stdout.write
I=lambda:[*map(int,inpu().split())]

t = I()[0]
for _ in range(t):
	n, k, x = I()
	x -= 1
	s = inpu().strip()
	broken = []
	curr = s[0]
	start = 0
	for i in range(n):
		if s[i] != curr:
			broken.append(curr * (i - start))
			curr = s[i]
			start = i
	broken.append(curr * (n - start))
	ind = len(broken) - 1
	while x > 0:
		if broken[ind][0] == 'a':
			ind -= 1
			continue
		base = k * len(broken[ind]) + 1
		a = x % (base)
		broken[ind] = a * 'b'
		ind -= 1
		x //= base
	for i in range(len(broken)):
		if '*' in broken[i]:
			broken[i] = ''
	print(''.join(broken))