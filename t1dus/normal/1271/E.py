def gg(n,lol):
	ans = 0
	cur = 1
	lol2 = lol
	while(2*lol+1<=n):
		cur *= 2
		ans += cur
		lol = 2*lol+1
		lol2 *= 2
	if lol2*2 <= n:
		ans += n-lol2*2+1	
	return ans

n,k = map(int,input().split())
low = 1
high = n//2
res = 1
while low <= high:
	mid = (low+high)//2
	if gg(n,mid) >= k:
		res = mid
		low = mid+1
	else:
		high = mid-1
if n == k:
	print(1)
elif(gg(n,res)-1-gg(n,res*2) >= k):
	print(res*2+1)
else:
	print(res*2)