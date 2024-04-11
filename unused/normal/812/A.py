d = []
for _ in xrange(4):
    d.append(map(int, raw_input().split()))

for i in xrange(4):
    if d[i][3] == 0:
        continue
    for j in xrange(-1, 2):
        if d[(i+4+j)%4][1 - j] == 1:
            print 'YES'
            exit()
    for j in xrange(3):
        if d[i][j] == 1:
            print 'YES'
            exit()
    if d[(i+2)%4][1] == 1:
        print 'YES'
        exit()
print 'NO'