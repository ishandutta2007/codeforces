a=[int(k) for k in raw_input().split(" ")]
b=[int(k) for k in raw_input().split(" ")]

aa=[(a[i],a[i+1]) for i in range(0,8,2)]
bb=[(b[i],b[i+1]) for i in range(0,8,2)]

mna=min(a[0],a[2],a[4],a[6])
mxa=max(a[0],a[2],a[4],a[6])
mna2=min(a[1],a[3],a[5],a[7])
mxa2=max(a[1],a[3],a[5],a[7])
res=False

mnb=min(b[0],b[2],b[4],b[6])
mxb=max(b[0],b[2],b[4],b[6])
mnb2=min(b[1],b[3],b[5],b[7])
mxb2=max(b[1],b[3],b[5],b[7])

c=((mnb+mxb)/2,(mnb2+mxb2)/2)
l=(mxb-mnb)/2

for li in range(-100,101):
    for co in range(-100,101):
        i=(li,co)
        if i[0]<=mxa and i[0]>=mna and i[1]<=mxa2 and i[1]>=mna2:
            if abs(i[0]-c[0])+abs(i[1]-c[1])<=l:
                res=True
            
#    
#        
#        
#for i in bb:
#	if i[0]<=mxa and i[0]>=mna and i[1]<=mxa2 and i[1]>=mna2:
#		res=True
#		print i
#
#for i in aa:
#	if abs(i[0]-c[0])+abs(i[1]-c[1])<=l:
#		res=True
#		print i
if res:
	print "YES"
else:
	print "NO"