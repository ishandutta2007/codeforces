n, m = map(int, input().split())
a = list(map(int, input().split()))
a.sort()

acc = [[0] for _ in range(m)]
for i in range(n):
    acc[i % m].append(acc[i % m][-1] + a[i])

ans = [0] * n
cnt = 0
day = 1
for i in range(n):
    ans[-1] += a[n-1-i] * day
    cnt += 1
    if cnt == m:
        day += 1
        cnt = 0
cnt = 0
k = -1
for i in range(n-1, 0, -1):
    ans[i-1] = ans[i] - acc[i%m][k]
    cnt += 1
    if cnt == m:
        k -= 1
        cnt = 0

print(*ans)