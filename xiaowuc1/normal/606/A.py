a, b, c = (int(qq) for qq in raw_input().split())
x, y, z = (int(qq) for qq in raw_input().split())

bad = False

while not bad and (a < x or b < y or c < z):
	if a < x:
		if b-2 >= y:
			a += 1
			b -= 2
		elif c-2 >= z:
			a += 1
			c -= 2
		else:
			bad = True
	elif b < y:
		if a-2 >= x:
			b += 1
			a -= 2
		elif c-2 >= z:
			b += 1
			c -= 2
		else:
			bad = True
	else:
		if a-2 >= x:
			c += 1
			a -= 2
		elif b-2 >= y:
			c += 1
			b -= 2
		else:
			bad = True

print "No" if bad else "Yes"