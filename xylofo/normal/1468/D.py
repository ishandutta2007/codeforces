for _ in range(int(input())):
    n, m, a, b = map(int,input().split())
    if a > b:
        a = n+1-a
        b = n+1-b
    canStand = b-a-1
    s = list(map(int,input().split()))
    s.sort()
    i = min(canStand, len(s)) - 1
    timeUntillCapture = b-2
    ans = 0
    while i >= 0:
        if s[i] <= timeUntillCapture:
            ans += 1
            timeUntillCapture -= 1
        i -= 1
    print(ans)