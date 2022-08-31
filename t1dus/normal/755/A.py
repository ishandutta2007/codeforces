def is_prime(x):
	if x == 2:
		return True
	elif x == 1:
		return False
	if x%2 == 0:
		return False
	c = 3
	while (c*c <= x+1):
		if x%c == 0:
			return False
		c += 2
	return True
n = int(input())
for i in range(1,1001):
	if not is_prime((n*i)+1):
		print(i)
		break