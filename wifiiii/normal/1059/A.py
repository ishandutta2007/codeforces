n,L,a = [int(i) for i in input().split(' ')]
ans, pre = 0, 0
for i in range(n):
	t,l = [int(i) for i in input().split(' ')]
	ans += (t-pre) // a
	pre = t+l
ans += (L-pre) // a
print(ans)