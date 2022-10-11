def valid(s, t):
    i = 0
    j = 0
    while i < len(s) and j < len(t):
        if s[i] == t[j]:
            i += 1
            j += 1
        else:
            i += 1
    return j == len(t)

s = raw_input()
t = raw_input()
ret = 0
for j in xrange(len(s)+1):
    for i in xrange(j+1):
        cand = s[:i] + s[j:]
        if valid(cand, t):
            ret = max(ret, len(s) - len(cand))
print ret