n,a=[int(k) for k in raw_input().split(" ")]
##allangles=[0]*(n-2)
##for i in range(1,n-1):
##    j=i+1
##    aoi=(360.0*min(i,n-i)/n)
##    aoj=(360.0*min(j,n-j)/n)
##    oai=(180-aoi)/2
##    oaj=(180-aoj)/2
##    allangles[i-1]=abs(oai-oaj)
##    if j+i==n:
##        allangles[i-1]=oai+oaj
##
##print allangles

angleunite=(180-360.0/n)/(n-2)

i=1
br=abs(angleunite-a)
while abs((i+1)*angleunite-a)<br and i<n-2:
    br=abs((i+1)*angleunite-a)
    i+=1
print 2,1,(i+2)