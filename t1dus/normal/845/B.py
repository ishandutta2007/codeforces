a = [int(i) for i in input()]
b = a[:3]
c = a[3:]
if sum(b) == sum(c):
    print(0)
else:
    if sum(b) > sum(c):
        b,c = c[::],b[::]
    diff = sum(c)-sum(b)
    mx = []
    for i in b:
        mx.append(9-i)
    for i in c:
        mx.append(i)
    ans = 0
    cur = 0
    mx.sort(reverse = True)
    i = 0
    while cur < diff:
        ans += 1
        cur += mx[i]
        i += 1
    print(ans)