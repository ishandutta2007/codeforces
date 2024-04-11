n = int(raw_input())
amt = []
price = []
for _ in xrange(n):
	a, b = (int(x) for x in raw_input().split())
	amt.append(a)
	price.append(b)

ret = 0
low = 100
for _ in xrange(n):
	low = min(low, price[_])
	ret += amt[_] * low

print ret