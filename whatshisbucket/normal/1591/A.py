import sys
inpu = sys.stdin.readline
prin = sys.stdout.write

t = int(inpu())
for _ in range(t):
	n = int(inpu())
	a = list(map(int, inpu().split()))
	height = 1
	prev = -1
	for guy in a:
		if guy == 1 and height != 0:
			height += 1
			if prev == 1:
				height += 4
		if guy == 0 and prev == 0:
			height = 0
		prev = guy
	print(-1 if height == 0 else height)