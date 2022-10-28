import sys
I = lambda: [*map(int, sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	s = [*map(int, [*input()])]
	for i in range(len(s) - 1, 0, -1):
		if s[i] + s[i - 1] >= 10:
			t = s[:i - 1]
			t.append(s[i] + s[i - 1])
			t += s[i + 1:]
			print(''.join(str(guy) for guy in t))
			break
	else:
		t = [s[0] + s[1]] + s[2:]
		print(''.join(str(guy) for guy in t))