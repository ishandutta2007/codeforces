def get(s):
    lhs = 1e9
    rhs = -1e9
    for i in xrange(len(s)):
        if s[i] == '1':
            lhs = min(lhs, i)
            rhs = max(rhs, i)
    return lhs, rhs

r, c = (int(x) for x in raw_input().split())
c += 2
l = [raw_input() for _ in xrange(r)][::-1]
while len(l) and get(l[-1])[0] == 1e9:
    l.pop()
if len(l) == 0:
    print 0
elif len(l) == 1:
    print get(l[0])[1]
else:
    lhs, rhs = get(l[0])
    if lhs >= 1e9:
        dp = [0, c-1]
    else:
        dp = [2*rhs, c-1]
    for i in xrange(1,len(l)-1):
        ndp = [1e9, 1e9]
        lhs, rhs = get(l[i])
        ndp[0] = min(ndp[0], dp[1] + c)
        if lhs > 1e6:
            ndp[0] = min(ndp[0], dp[0] + 1)
        else:
            ndp[0] = min(ndp[0], dp[0] + 1 + 2 * rhs)
        ndp[1] = min(ndp[1], dp[0] + c)
        if lhs > 1e6:
            ndp[1] = min(ndp[1], dp[1] + 1)
        else:
            ndp[1] = min(ndp[1], dp[1] + 1 + 2 * (c-1-lhs))
        dp = ndp
    lhs, rhs = get(l[-1])
    ret = 1e9
    ret = min(ret, dp[0] + 1 + rhs)
    ret = min(ret, dp[1] + 1 + (c-1-lhs))
    print ret