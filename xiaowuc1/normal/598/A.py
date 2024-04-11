def solve():
    n = int(raw_input())
    ret = n*(n+1) / 2
    a = 1
    while a <= n:
        ret -= 2 * a
        a *= 2
    print ret

qq = int(raw_input())
for _ in xrange(qq):
    solve()