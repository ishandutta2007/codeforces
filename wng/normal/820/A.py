c,v0,v1,a,l=[int(k) for k in raw_input().split(" ")]

d=0
r=0

while r<c:
    read=0
    if d>0:
        read-=min(l,r)
    read+=min(v1,v0+a*d)
    r+=read
    d+=1
  #  print "day {} read {}".format(d,r)
print d