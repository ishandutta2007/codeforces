from itertools import accumulate

n, m, dmax = map(int, input().split())
c = list(map(int, input().split()))

if sum(c) - m + dmax * (m+1) < n+1:
    print('NO')
    exit()
else:
    print('YES')

d = (n - sum(c)) // (m+1)
major_num = (n - sum(c)) - d * (m+1)

ans = []
k = 1
for i in range(major_num):
    ans.extend([0] * (d + 1))
    ans.extend([k] * c[k-1])
    k += 1
for i in range(m + 1 - major_num - 1):
    ans.extend([0] * d)
    ans.extend(([k] * c[k-1]))
    k += 1
ans.extend(([0] * d))
print(*ans)