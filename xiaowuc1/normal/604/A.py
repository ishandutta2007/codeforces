vals = [500, 1000, 1500, 2000, 2500]
m = [int(x) for x in raw_input().split()]
w = [int(x) for x in raw_input().split()]
h = [int(x) for x in raw_input().split()]
ret = 100 * h[0] - 50 * h[1]
for i in xrange(5):
	ret += max(vals[i] * 3 / 10, (250 - m[i]) * vals[i] / 250 - 50 * w[i])
print ret