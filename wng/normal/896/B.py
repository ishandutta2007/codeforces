import sys
n,m,c=[int(k) for k in raw_input().split(" ")]

if c==1:
    for j in range(n):
        nn=int(raw_input())-1
        print j+1
        sys.stdout.flush()
else:
    comin=[i*(n-1)/(c-1) for i in range(c)]
    comax=[i*(n-1)/(c-1) for i in range(c)]
    
    wheretoput=[1]*c
    nba=0
    holes=set(range(1,n+1))
    
    while nba<n:
        nn=int(raw_input())-1
        onn=nn
        mn=comin[nn]
        mx=comax[nn]
        if comax[nn]>=n:
            wheretoput[nn]=0
        if comin[nn]==0:
            wheretoput[nn]=1
        #choose where we put this shit.    
        wtp=wheretoput[nn]
        if wtp==1:
            comax[nn]+=1        
            mnew=comax[nn]-1
            mx+=1
            nba+=1
            while nn<c-1 and comin[nn+1]<mx:
                comin[nn+1]+=1
                if comax[nn+1]>=comin[nn+1]:
                    nba-=1
                else:
                    comax[nn+1]=comin[nn+1]
                nn+=1
        if wtp==0:
            comin[nn]-=1      
            mnew=comin[nn]
            mn-=1
            nba+=1
            while nn>0 and comax[nn-1]>mn:
                comax[nn-1]-=1
                if comin[nn-1]<=comax[nn-1]:
                    nba-=1
                else:
                    comin[nn-1]=comax[nn-1]
                nn-=1
        print mnew+1
        sys.stdout.flush()
        if mnew+1 in holes:
            holes.discard(mnew+1)
        if (len(holes)>0 and min(holes)>comin[onn]):
            wheretoput[onn]=1
        elif  (len(holes)>0 and max(holes)<comax[onn]):
            wheretoput[onn]=0
        elif onn!=nn:
            wheretoput[onn]=1-wheretoput[onn]
        #print comin,comax,nba