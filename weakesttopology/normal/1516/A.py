t = int(input())
for z in range(t):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))

    for i in range(n - 1):
        x = min(k, a[i])
        a[i] -= x
        a[-1] += x
        k -= x

    print(*a)