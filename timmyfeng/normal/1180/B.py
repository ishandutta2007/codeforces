n = input()
a = map(int, raw_input().split())

for i in range(n):
    if a[i] >= 0:
        a[i] = -a[i] - 1

if n % 2:
    ndx = a.index(min(a))
    a[ndx] = -a[ndx] - 1

print(' '.join([str(x) for x in a]))