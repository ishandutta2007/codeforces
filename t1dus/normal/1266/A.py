for _ in range(int(input())):
	y = input()
	a1 = 0
	a2 = 0
	a3 = 0
	for i in y:
		k = int(i)
		if a1 == 0 and k == 0: a1 = 1
		elif k%2 == 0:
			a2 = 1
		a3 += k
	if a3%3 == 0 and a1 and a2:
		print("red")
	else:
		print("cyan")