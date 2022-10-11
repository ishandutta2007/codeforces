s = raw_input()
ret = 0
for i in xrange(len(s)):
    for j in xrange(i):
        for k in xrange(j):
            if s[k] == 'Q' and s[j] == 'A' and s[i] == 'Q':
                ret += 1
print ret