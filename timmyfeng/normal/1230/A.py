a = sorted(map(int, raw_input().split()))
print('YES' if a[3] == a[0] + a[1] + a[2] or a[0] + a[3] == a[1] + a[2] else 'NO')