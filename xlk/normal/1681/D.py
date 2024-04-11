from functools import lru_cache
n, x = map(int, input().split())
@lru_cache(None)
def F(x):
	if len(str(x)) >= n:
		return 0
	z = 100
	for i in range(2, 10):
		if str(i) in str(x):
			z = min(z, F(x * i) + 1)
	return z
z = F(x)
if z == 100:
	z = -1
print(z)