import sys
inpu=sys.stdin.readline
prin=sys.stdout.write
I=lambda:[*map(int,inpu().split())]

t = I()[0]
for _ in range(t):
	s = input().strip()
	if s.count("N") == 1:
		print("NO")
	else:
		print("YES")