n, x, y = map(int, raw_input().split())
a = map(int, raw_input().split())

for i in range(n):
    ok = True
    for j in range(max(0, i - x), min(n, i + y + 1)):
        ok &= (a[i] <= a[j])
    if ok:
        print(i + 1)
        break