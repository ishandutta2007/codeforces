n,d=map(int,raw_input().split())
a,b=map(int,raw_input().split())
p,c,s=[],[],0
for i in xrange(n):
    x,y=map(int,raw_input().split())
    c.append([x*a+y*b,i+1])
c.sort()
for x,y in c:
    if (s+x>d): break
    s+=x
    p.append(str(y))
print str(len(p))+'\n'+str(' '.join(p))