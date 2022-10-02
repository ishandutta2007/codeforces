a, b = map(int, raw_input().split())

aa = 0
ab = 0
bb = 0
for i in xrange(1, 7):
	da = abs(a-i)
	db = abs(b-i)
	if da < db:
		aa += 1
	elif da > db:
		bb += 1
	else:
		ab += 1
print aa, ab, bb