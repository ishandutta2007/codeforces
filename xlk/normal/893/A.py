x = 3
for i in range(input()):
	y = input()
	if x == y:
		print 'NO'
		break
	x = 6 - x - y
else:
	print 'YES'