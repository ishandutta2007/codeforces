Q = int(input())
for q in range(Q):
    n = int(input())
    a = list(map(int, input().split()))
    idx = {}
    for i in range(n):
        idx[a[i]] = i
    used = [0] * (n-1)
    k = 1
    while k < n+1:
        if idx[k] > 0:
            if used[idx[k] - 1] == 0 and a[idx[k]] < a[idx[k] - 1]:
                used[idx[k] - 1] = 1
                a[idx[k]], a[idx[k] - 1] = a[idx[k] - 1], a[idx[k]]
                idx[a[idx[k]]], idx[a[idx[k] - 1]] = idx[a[idx[k] - 1]], idx[a[idx[k]]]
            else:
                k += 1
        else:
            k += 1
    ans = [0] * n
    for i in range(1, n+1):
        ans[idx[i]] = i
    print(*ans)