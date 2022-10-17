import sys
f = 'What are you doing at the end of the world? Are you busy? Will you save us?'
g0 = 'What are you doing while sending "'
g1 = '"? Are you busy? Will you send "'
g2 = '"?'

lf = [len(f)]
for i in range(100020):
	lf.append(min(len(g0) + lf[-1] + len(g1) + lf[-1] + len(g2), 10 ** 20))

def F(n, k):
	while True:
		if k >= lf[n]:
			return '.'
		if n == 0:
			return f[k]
		if k < len(g0):
			return g0[k]
		k -= len(g0)
		if k < lf[n - 1]:
			n -= 1
			continue
		k -= lf[n - 1]
		if k < len(g1):
			return g1[k]
		k -= len(g1)
		if k < lf[n - 1]:
			n -= 1
			continue
		k -= lf[n - 1]
		if k < len(g2):
			return g2[k]
		assert False

for _ in range(input()):
	n, k = map(int, raw_input().split())
	sys.stdout.write(F(n, k - 1))
print