def swap(dp, a, b):
	x = None
	y = None
	for z in dp:
		if dp[z] == a:
			x = z
		if dp[z] == b:
			y = z
	dp[x] = b
	dp[y] = a

qqq, n = (int(x) for x in raw_input().split())

s = raw_input()

dp = dict()
for i in xrange(26):
	c = chr(i + ord('a'))
	dp[c] = c

for _ in xrange(n):
	a, b = (x for x in raw_input().split())
	swap(dp, a, b)

t = [dp[x] for x in s]
print "".join(t)