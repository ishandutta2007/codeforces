n, k = list(map(int, input().split()))
s = list(map(int, input().split()))
c = [ 0 for i in range(200000 + 1) ]
for i in s: c[i - 1] += 1
p = list(range(200000))
p.sort(key=lambda x: c[x], reverse=True)
ans = 0
res = []
for i in range(k):
    res.append(s[i])

def check(t):
    v = []
    global res
    for i in p:
        cnt = c[i] // t
        for j in range(cnt):
            if len(v) == k:
                break
            v.append(i)
        if len(v) == k:
            break
    if len(v) == k:
        res = v
        return True
    else:
        return False

for d in range(20, -1, -1):
    if (ans + (1 << d)) * k > n: continue
    if check(ans + (1 << d)):
        ans += (1 << d)

for i in res: print(i + 1, end=' ')