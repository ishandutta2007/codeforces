n, nC = map(int, raw_input().split())
a = map(int, raw_input().split())

a_min = min(a)

if max(a) - min(a) > nC:
    print 'NO'
    exit()

print 'YES'
for i in range(n):
    for j in range(a_min):
        print 1,
    for j in range(a_min, a[i]):
        print j - a_min + 1,
    print