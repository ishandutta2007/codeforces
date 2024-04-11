from collections import defaultdict
def solve():
    n = int(raw_input())
    dp = defaultdict(int)
    s = [x for x in raw_input()]
    t = [x for x in raw_input()]
    for x in s:
        dp[x] += 1
    for x in t:
        dp[x] += 1
    for x in dp:
        if dp[x]%2:
            print "No"
            return
    print "Yes"
    ret = []
    i = 0
    while i < len(s)-1:
        if s[i] == t[i]:
            i += 1
            continue
        j = i+1
        found = False
        while j < len(s):
            if s[i] == s[j]:
                x = s[j]
                s[j] = t[i]
                t[i] = x
                ret.append((j+1, i+1))
                found = True
                break
            j += 1
        if found:
            continue
        j = i
        while j < len(s):
            if s[i] == t[j]:
                x = s[n-1]
                s[n-1] = t[j]
                t[j] = x
                ret.append((n, j+1))
                found = True
                break
            j += 1
        assert found

    print len(ret)
    for x in ret:
        print '{} {}'.format(x[0], x[1])

t = int(raw_input())
for _ in xrange(t):
    solve()