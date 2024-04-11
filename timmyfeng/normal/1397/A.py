t = input()
for tt in xrange(t):
    n = input()
    cnt = [0] * 26
    for i in xrange(n):
        for j in raw_input():
            cnt[ord(j) - ord('a')] += 1
    ok = True
    for i in cnt:
        ok &= (i % n == 0)
    print 'Yes' if ok else 'No'