n=int(input())
a=map(int,raw_input().split(' '))
m=min(a)
if (a.count(m)>1):
    print "Still Rozdil"
else:
    print 1+a.index(m)