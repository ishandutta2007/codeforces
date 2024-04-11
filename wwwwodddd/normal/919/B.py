k = input()
i = 1
while True:
	t = sum(map(int, str(i)))
	if t == 10:
		k -= 1
	if t > 10:
		u = i
		v = 1
		while u % 10 == 0:
			u /= 10
			v *= 10
		v *= 10
		i = (i / v + 1) * v
		continue
	if k == 0:
		print i
		break
	i += 1