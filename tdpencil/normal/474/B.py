n = int(input())


lst = list(map(int, input().split()))
pref = [0 for i in range(n)]
pref[0] = lst[0]
for i in range(1, n):
    pref[i] = pref[i - 1] + lst[i]

m = int(input())
query = list(map(int, input().split()))
for i in range(m):
    qq = query[i]
    l, r = (0, n - 1)
    while l < r:
        mid = (l + r) // 2
        if pref[mid] >= qq:
            r = mid
        else:
            l = mid + 1
    assert l >= 0 and l < n 
    if pref[l] < qq:
        l -= 1
    print(l + 1)