n = int(input())
a = list(map(int,input().split()))
s = 0
ret = 0
mp = {}
for i in range(len(a)):
    ret += a[i] * i - s
    if a[i] - 1 in mp:ret -= mp[a[i] - 1]
    if a[i] + 1 in mp:ret += mp[a[i] + 1]
    if a[i] in mp:mp[a[i]] += 1
    else: mp[a[i]] = 1
    s += a[i]
print(ret)