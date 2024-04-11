import sys
I = lambda:[*map(int, sys.stdin.readline().split())]

n = int(input())
sml = 1
big = n + 1
while big - sml > 1:
	mid = (big + sml) // 2
	mod = mid % n
	print('+', n - mod)
	sml += n - mod
	big += n - mod
	mid += n - mod
	r = mid // n
	x = int(input())
	if x == r:
		sml = mid
	else:
		big = mid

print('!', sml)