s = raw_input()
r = 0
while s[r] != 'R':
    r+=1
g = 0
while s[g] != 'G':
    g+=1
y = 0
while s[y] != 'Y':
    y+=1
b = 0
while s[b] != 'B':
    b+=1
rr = 0
bb = 0
yy = 0
gg = 0
for i in xrange(len(s)):
    if s[i] == '!':
        if i%4 == r%4:
            rr += 1
        if i%4 == y%4:
            yy += 1
        if i%4 == b%4:
            bb += 1
        if i%4 == g%4:
            gg += 1
print "{} {} {} {}".format(rr,bb,yy,gg)