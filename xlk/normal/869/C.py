a, b, c = map(int, raw_input().split())
p = 998244353
def F(a, b):
	if a > b:
		a, b = b, a
	re = 0
	t = 1
	for i in range(a + 1):
		re = (re + t) % p
		t = t * (a - i) * (b - i) * pow(i + 1, p - 2, p) % p
	return re
print F(a, b) * F(b, c) * F(c, a) % p