

#[int(k) for k in raw_input().split(" ")]

dc=[[1 for j in range(1+k)] for k in range(1001)]
mod=10**9+7
for k in range(1,1001):
    for j in range(1,k):
        dc[k][j]=(dc[k-1][j]+dc[k-1][j-1])%mod


nb=raw_input()
n=int(nb,2)
k=int(raw_input())

if k==0:
    print 1
else:
    nbkm=len(nb)
    
    #number of steps of number that contains k i (1 is special case)
    d={1:1}
    res=0    
    for kk in range(2,nbkm+1):
        nb1k=len([i for i in bin(kk) if i=='1'])    
        d[kk]=d[nb1k]+1
    #OK apres je dois compter cb de nombres <=n have the numbers that give have 
    for kk in range(1,nbkm+1):
        kkk=kk
        if d[kk]==k:
            nn=nb
            addres=dc[len(nn)][kk]
            ynkp=0
            while len(nn)>0:            
                if nn[0]=="1":
                    kk-=1
                else:
                    if kk>=1 and kk<=len(nn):
                        ynkp+=dc[len(nn)-1][kk-1]
                nn=nn[1:]
            addres=(addres-ynkp)%mod
            res=(res+addres)%mod
#            print "case {} done. Added {}. Total {}".format(kkk,addres,res)
    if k==1: #On a compte une fois de trop 1
        print res-1
    else:
        print res