a, b = map(int, input().split())
if b <= (a + b) // 2:
    k = 1
    for i in range(29, -1, -1):
        nk = k + (1 << i)
        if b <= (a + b) // (2 * nk):
            k = nk
    x = (a + b) / (2 * k)
    print('{:.10f}'.format(x))
else:
    print(-1)