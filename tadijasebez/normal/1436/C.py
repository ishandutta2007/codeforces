mod = 1000000007

n, x, pos = map(int, input().split())

top, bot, lo, hi = n, 0, 0, 0
while top>bot:
	mid = top+bot>>1
	if mid>pos:
		hi += 1
		top = mid
	else:
		if mid<pos:
			lo += 1
		bot = mid+1

F, I = [1 for _ in range(n+1)], [1 for _ in range(n+1)]
for i in range(1, n+1):
	F[i] = i*F[i-1]%mod
for i in range(2, n+1):
	I[i] = (mod-mod//i)*I[mod%i]%mod
for i in range(1, n+1):
	I[i] = I[i]*I[i-1]%mod

def binom(n, k):
	if n<k or k<0:
		return 0
	else:
		return F[n]*I[k]%mod*I[n-k]%mod

ans = binom(n-x, hi)*F[hi]%mod*binom(x-1, lo)%mod*F[lo]%mod*F[n-hi-lo-1]%mod
print(ans)