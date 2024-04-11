a, b = map(int, raw_input().split())
while True:
	if a == 0 or b == 0:
		break
	if a >= 2 * b:
		a %= 2 * b
	elif b >= 2 * a:
		b %= 2 * a
	else:
		break
print a, b