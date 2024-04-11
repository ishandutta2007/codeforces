t = int(input())
for _ in range(t):
    N = int(input())
    p = list(map(int, input().split()))

    idx = {}
    for i in range(N):
        idx[p[i]] = i
    left = N+1
    right = -1
    ans = [0] * N
    for i in range(1, N+1):
        x = idx[i]
        if x < left:
            left = x
        if x > right:
            right = x
        if right - left + 1 == i:
            ans[i-1] = 1
    print(''.join(map(str, ans)))