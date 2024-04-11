
import sys


n=int(input())
n2=n*n
listw=[]
listb=[]
for i in range(n):
    for j in range(n):
        if (i+j)%2:
            listw+=[(i,j)]
        else:
            listb+=[(i,j)]
nbw=len(listw)
nbb=len(listb)

ib=0
iw=0
for i in range(n2):
    a=int(input())
    
    if (ib<nbb and iw<nbw):
        if a!=1:
            b=1
            si,sj=listb[ib]
            ib+=1
        else:
            b=2
            si,sj=listw[iw]
            iw+=1
    else:
        if (ib==nbb):
            if a!=2:
                b=2
            else:
                b=3
            si,sj=listw[iw]
            iw+=1
        elif (iw==nbw):
            if a!=1:
                b=1
            else:
                b=3
            si,sj=listb[ib]
            ib+=1
    print(b,si+1,sj+1)
    sys.stdout.flush()