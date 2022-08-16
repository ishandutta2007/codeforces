def check(x):
	a = list(str(x))
	return len(a) == len(set(a))

x = int(input())
while True:
	x += 1
	if check(x):
		print(x)
		break