import sys
range = xrange
input = raw_input

t = int(input())

for _ in range(t):
    n, k = [ int(x) for x in input().split() ]

    ans = []
    if n >= k and (n - k) % 2 == 0:
        for i in range(k - 1):
            ans.append(1)
        ans.append(n - (k - 1))
    elif n >= 2 * k and (n - 2 * k) % 2 == 0:
        for i in range(k - 1):
            ans.append(2)
        ans.append(n - 2 * (k - 1))

    if len(ans) > 0:
        print 'YES'
        print ' '.join(str(x) for x in ans)
    else:
        print 'NO'