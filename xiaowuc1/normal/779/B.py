s = raw_input()
n = s.split()[0]
k = int(s.split()[1])
ret = 100
for mask in xrange(2 ** len(n)):
    t = ""
    for i in xrange(len(n)):
        if mask & (2**i):
            t += s[i]
    if t and str(int(t)) == t and int(t) % (10**k) == 0:
        ret = min(ret, len(n) - len(t))
print ret