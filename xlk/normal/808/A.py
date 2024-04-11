def low(n):
	t = 10 ** 12
	while n % t > 0:
		t /= 10
	return t

m = n = input()
n += 1
while True:
	if len(str(n)) - str(n).count('0') == 1:
		break
	n += low(n)
print n - m