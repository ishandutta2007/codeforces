r, c = (int(x) for x in raw_input().split())
dp = [1e9] * 8
dp[0] = 0

alpha = [
	"1234567890",
	"qwertyuiopasdfghjklzxcvbnm",
	"#*&"
]

for _ in xrange(r):
	s = raw_input()
	next = [1e9] * 8
	for i in xrange(c):
		for j in xrange(len(dp)):
			for k in xrange(3):
				if s[i] in alpha[k]:
					next[j | (2**k)] = min(next[j | (2**k)], dp[j] + min(i, c-i))
	for i in xrange(8):
		dp[i] = next[i]
print dp[7]