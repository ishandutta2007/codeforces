n = int(input())
a = list(map(int, input().split()))

mn = [-1 for _ in range(n*4)]
def Set(c, ss, se, qi, f):
	if ss==se:
		mn[c] = f
	else:
		mid = ss+se>>1
		if qi<=mid:
			Set(c*2, ss, mid, qi, f)
		else:
			Set(c*2+1, mid+1, se, qi, f)
		mn[c] = min(mn[c*2], mn[c*2+1])
def Walk(c, ss, se, k):
	if ss==se:
		return ss+1 if mn[c]>k else ss
	mid = ss+se>>1
	if mn[c*2]>k:
		return Walk(c*2+1, mid+1, se, k)
	else:
		return Walk(c*2, ss, mid, k)

las = [-1 for _ in range(n+2)]
was = [False for _ in range(n+3)]
for i in range(n):
	if las[a[i]]!=i-1:
		was[Walk(1, 1, n, las[a[i]])] = True
	las[a[i]] = i
	Set(1, 1, n, a[i], i)
for i in range(1, n+2):
	if las[i]!=n-1:
		was[Walk(1, 1, n, las[i])] = True

ans = 1
while was[ans]:
	ans += 1
print(ans)