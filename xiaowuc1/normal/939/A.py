n = int(raw_input())
l = [int(x)-1 for x in raw_input().split()]
valid = 0
for i in xrange(n):
    if i != l[i] and l[l[l[i]]] == i:
        valid += 1
print "YES" if valid else "NO"