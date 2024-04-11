n = input()
a = sorted(map(int, raw_input().split()))

if a[n - 1] >= a[n - 2] + a[n - 3]:
    print('NO')
else:
    print('YES')
    print(' '.join(str(i) for i in (a[:n - 2] + [a[n - 1], a[n - 2]])))