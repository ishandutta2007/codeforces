range = xrange
input = raw_input

n = int(input())
a = [int(x) for x in input().split()]

cur = 0
mp = {}
for i in a:
    cur += i
    if i in mp:
        mp[i] += 1
    else:
        mp[i] = 1

ans = 0
for i in range(n):
    res = cur
    cnt = n - i

    for j in range(a[i] - 1, a[i] + 2):
        if j in mp:
            res -= mp[j] * j
            cnt -= mp[j]

    ans += res - cnt * a[i]
    cur -= a[i]
    mp[a[i]] -= 1

print(ans)