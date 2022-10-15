t = int(input())
for _ in range(t):
    s = input()
    n = len(s)
    a = [None] * n
    for i, x in enumerate(s):
        if x != '?':
            x = ord(x) - ord('0')
            a[i] = (x == i % 2)
    last = [-1, -1]
    ans = 0
    for i, x in enumerate(a):
        if x is None:
            ans += i - min(*last)
        else:
            ans += i - last[x ^ 1]
            last[x] = i
    print(ans)