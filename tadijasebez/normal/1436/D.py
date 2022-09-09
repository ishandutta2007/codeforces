n = int(input())
deg = [0 for _ in range(n)]
p = list(map(int, input().split()))
for i in range(n-1):
	p[i] -= 1
	deg[p[i]] += 1
a = list(map(int, input().split()))
sz = [0 if deg[i] else 1 for i in range(n)]
ans = 0
for i in range(n-1, 0, -1):
	sz[p[i-1]]+=sz[i]
	a[p[i-1]]+=a[i]
	ans = max(ans, (a[i]+sz[i]-1)//sz[i])
ans = max(ans, (a[0]+sz[0]-1)//sz[0])
print(ans)