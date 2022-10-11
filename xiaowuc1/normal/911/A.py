n = int(raw_input())
l = [int(x) for x in raw_input().split()]
v = min(l)
t = [i for i in xrange(n) if l[i] == v]
tt = [t[i+1] - t[i] for i in xrange(len(t)-1)]
print min(tt)