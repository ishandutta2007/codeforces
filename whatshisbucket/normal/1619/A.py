import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t,=I()
for _ in range(t):
	s = input()
	l = len(s)
	if l % 2 == 0 and s[:l//2] == s[l//2:]:
		print('YES')
	else:
		print('NO')