from __future__ import division
x,h,m = 0,0,0
x = int(raw_input())
s = raw_input()
h = int(s.split(" ")[0])
m = int(s.split(" ")[1])
if '7' in str(h) or '7' in str(m):
    print 0
    exit()
for i in range(1,10000):
    m-=x
    while m<0:
        m+=60
        h-=1
    while h<0:
        h+=24
    if '7' in str(h) or '7' in str(m):
        print i
        break