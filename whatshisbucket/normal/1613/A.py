t = int(input())
import math
for i in range(t):
	x1, p1 = map(int, input().split())
	x2, p2 = map(int, input().split())
	l1 = math.log10(x1) + p1
	l2 = math.log10(x2) + p2
	if abs(l1 - l2) < .0000001:
		print('=')
	elif l1 > l2:
		print('>')
	else:
		print('<')