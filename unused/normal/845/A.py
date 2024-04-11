n = int(input())
a = list(map(int, input().split()))
a.sort()
if a[n - 1] == a[n]:
    print('NO')
else:
    print('YES')