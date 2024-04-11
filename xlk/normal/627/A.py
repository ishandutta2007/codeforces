s, x = map(int, raw_input().split())
b = (s - x)
c = bin(x).count('1')
if b % 2 == 1 or ((b / 2) & x) > 0:
	print 0
elif b == 0:
	print 2 ** c - 2
else:
	print 2 ** c