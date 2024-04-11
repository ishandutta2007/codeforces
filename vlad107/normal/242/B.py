n=input()
l,r=[0]*n,[0]*n
for i in xrange(n):l[i],r[i]=map(int,raw_input().split())
t,u=map(lambda x,y:[x,y],l,r),[min(l),max(r)]
if u in t:print 1+t.index(u)
else:print -1