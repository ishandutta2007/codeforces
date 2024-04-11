nlr=(raw_input()).split()
a=(raw_input()).split()
b=(raw_input()).split()
n=int(nlr[0])
l=int(nlr[1])
r=int(nlr[2])
al=a[0:l-1]
am=a[l-1:r]
ar=a[r:n]
bl=b[0:l-1]
bm=b[l-1:r]
br=b[r:n]
am=sorted(am)
bm=sorted(bm)
if al==bl and am==bm and ar==br:
  print "TRUTH"
else:
  print "LIE"