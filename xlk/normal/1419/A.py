t = int(input())
for tt in range(t):
	n = int(input())
	s = list(map(lambda x: int(x) % 2, input()[1-n%2::2]))
	if n % 2 == 1:
		if 1 in s:
			print(1)
		else:
			print(2)
	else:
		if 0 in s:
			print(2)
		else:
			print(1)