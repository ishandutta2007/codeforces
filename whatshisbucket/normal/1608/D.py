import sys
inpu = sys.stdin.readline
prin = sys.stdout.write
M = 998244353
def binom(n, m, mod):
	if m > n or m < 0:
		return 0
	fac = 1
	i = 1
	a, b, c = 1, 1, 1
	while i <= n:
		fac = (fac * i) % mod
		if i == m:
			a = fac
		if i == n - m:
			b = fac
		if i == n:
			c = fac
		i += 1
	x = (c * pow(a, -1, mod) * pow(b, -1, mod)) % mod
	return x
n = int(inpu())
blank = 0
xw = 0
wx = 0
bb = 0
ww = 0
bx = 0
xb = 0
bw = 0
wb = 0
for i in range(n):
	s = input()
	if s[0] == '?':
		if s[1] == '?':
			blank += 1
		elif s[1] == 'W':
			xw += 1
		elif s[1] == 'B':
			xb += 1
	elif s[0] == 'W':
		if s[1] == '?':
			wx += 1
		elif s[1] == 'W':
			ww += 1
		elif s[1] == 'B':
			wb += 1
	elif s[0] == 'B':
		if s[1] == '?':
			bx += 1
		elif s[1] == 'W':
			bw += 1
		elif s[1] == 'B':
			bb += 1

diff = ww - bb
k = blank
m = wx + xw
n = bx + xb
tot = binom(m + n + 2 * k, m + k + diff, M)
if ww == bb == 0:
	ways = pow(2, blank, M)
	if bw == 0 and xw == 0 and bx == 0:
		ways -= 1
	if wb == 0 and wx == 0 and xb == 0:
		ways -= 1
	tot -= ways
print(tot)