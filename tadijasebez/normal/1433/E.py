n = int(input())
F = [1]
for i in range(1,n+1):
	F.append(F[-1]*i)
def binom(n, k):
	return F[n]//F[k]//F[n-k]
print(binom(n,n//2) * F[n//2-1]**2 // 2)