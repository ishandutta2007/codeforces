import sys
import math
inpu = sys.stdin.readline
prin = sys.stdout.write

def pal(l):
	for i in range(len(l)//2):
		if l[i] != l[-i-1]:
			return False
	return True

t = int(inpu())
for _ in range(t):
	n = int(inpu())
	a = list(map(int, inpu().split()))
	bad = []
	for i in range(len(a) // 2):
		if a[i] != a[-i-1]:
			bad.append(a[i])
			bad.append(a[-i-1])
			break
	if len(bad) == 0:
		print("YES")
	else:
		for i in bad:
			b = [guy for guy in a if guy != i]
			if pal(b):
				print("YES")
				break
		else:
			print("NO")