import sys
range = xrange
input = raw_input

t = int(input())
out = []

for _ in range(t):
    n = int(input())
    a = [ int(x) for x in input().split() ]

    ps = [0]
    cur = 0
    for i in a:
        cur += i
        ps.append(cur)

    cnt = set()
    for i in range(1, n + 1):
        for j in range(i - 1):
            if ps[i] - ps[j] <= n:
                cnt.add(ps[i] - ps[j])
    
    ans = 0
    for i in a:
        if i in cnt:
            ans += 1
    print ans