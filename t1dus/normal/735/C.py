a = [1,1,2]
for i in range(3,201):
	a.append(a[i-1]+a[i-2])
n = int(input())
ans = 1
i = 3
while n >= a[i]:
	i += 1
	ans += 1
print(ans)