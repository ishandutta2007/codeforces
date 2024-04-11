z = mn = mx = 0
n, d = map(int, raw_input().split())
for x in map(int, raw_input().split()):
	mn += x
	mx += x
	mx = min(mx, d)
	if x == 0:
		mn = max(mn, 0)
		if mx < 0:
			mx = d
			z += 1
	if mn > d:
		print '-1'
		break
else:
	print z