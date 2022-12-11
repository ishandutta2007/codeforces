n = input()
st = {}
for _ in xrange(n):
    s = raw_input()
    s = s.replace('u', 'oo')
    while 'kh' in s:
        s = s.replace('kh', 'h')
    st[s] = 1
print len(st)