n = int(raw_input())
neg = 0
pos = 0
for _ in xrange(n):
    x, y = (int(z) for z in raw_input().split())
    if x > 0:
        pos += 1
    else:
        neg += 1
print "Yes" if neg <= 1 or pos <= 1 else "No"