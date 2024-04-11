import sys
range = xrange
input = raw_input

n, k = [ int(x) for x in input().split() ]
a = [ int(x) for x in input().split() ]

cnt = set()
b = []
for i in a:
    if i not in cnt:
        if len(b) >= k:
            cnt.remove(b[-k])
        b.append(i)
        cnt.add(i)
b.reverse()

print min(len(b), k)
print ' '.join([ str(x) for x in b[:k] ])