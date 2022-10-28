import sys
range = xrange
input = raw_input

t = int(input())

for _ in range(t):
    n = int(input())
    ans = []
    b = 1
    while n > 0:
        if n % 10 > 0:
            ans.append(n % 10 * b)
        b *= 10
        n //= 10
    print len(ans)
    print ' '.join(str(x) for x in ans)