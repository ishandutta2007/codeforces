from collections import defaultdict

n = int(raw_input())
a = []
b = []
for _ in xrange(n):
    x, y = (int(z) for z in raw_input().split())
    if x not in a:
        a.append(x)
    if y not in b:
        b.append(y)
a = sorted(a)
b = sorted(b)
if len(a) > 1 and len(b) > 1:
    print (a[1] - a[0]) * (b[1] - b[0])
else:
    print -1