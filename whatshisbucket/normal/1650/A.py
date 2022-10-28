import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	s = input().strip()
	c = input().strip()
	for i in range(len(s)):
		if s[i] == c and i % 2 == 0:
			print("YES")
			break
	else:
		print("NO")