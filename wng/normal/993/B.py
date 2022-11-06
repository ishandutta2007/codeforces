n,m=[int(k) for k in raw_input().split(" ")]
a=[int(k) for k in raw_input().split(" ")]
b=[int(k) for k in raw_input().split(" ")]
aa=[(a[i],a[i+1]) for i in range(0,2*n,2)]
bb=[(b[i],b[i+1]) for i in range(0,2*m,2)]
#print aa
#print bb
ma=[set() for i in range(n)]
mb=[set() for i in range(m)]
mt=set()

def common(u,v):
    return [k for k in u if k in v]
    
for i in range(n):
    ai=aa[i]
    for j in range(m):
        cij=common(ai,bb[j])
        if len(cij)==1:
            mt.add(cij[0])
            ma[i].add(cij[0])
            mb[j].add(cij[0])
          #  print "m :",ai,bb[j]

if len(mt)==1:
    print list(mt)[0]
elif max([len(k) for k in ma])==1 and max([len(k) for k in mb])==1:
    print 0
else:
    print -1