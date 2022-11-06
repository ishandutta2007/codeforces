s=raw_input()

C=[[0 for j in range(2*i+2)] for i in range(20)]
C[0][0]=1
for i in range(1,20):
    for j in range(i+1):
        C[i][j]=C[i-1][j]+C[i-1][j-1]

d={}

for k in s:
    i=int(k)
    if i not in d:
        d[i]=0
    d[i]+=1

res=0
n=sum(d.values())
k=len(d)
if 0 not in d:
    v=d.values()
    a=[0]*k
    suma=k
    while True:
        nbp=1
        l=suma
        for i in range(k):
            nbp*=C[l][a[i]+1]
        #    print nbp, l, a[i]+1
            l-=a[i]+1
        res+=nbp
      #  print nbp,a
        i=0
        while i<k and a[i]==v[i]-1:
            i+=1
        if i==k:
            break
        a[i]+=1
        suma+=1
        for j in range(i):
            a[j]=0
            suma-=v[j]-1
else:
    v=d.values()
    a=[0]*k
    suma=k
    while True:
        nbp=1
        l=suma
        for i in range(k):
            nbp*=C[l][a[i]+1]
            l-=a[i]+1
        res+=nbp
      #  print nbp,a
        i=0
        while i<k and a[i]==v[i]-1:
            i+=1
        if i==k:
            break
        a[i]+=1
        suma+=1
        for j in range(i):
            a[j]=0
            suma-=v[j]-1
    #print res,n 
    
    
    d[0]-=1
    ks=d.keys()
    n0=[kk for kk in range(len(d)) if not ks[kk]][0]
    v=d.values()
    k=len(d)
    n-=1
    ab=[0]*k
    ab[n0]=-1
    a=ab[:]
    suma=k-1
    while True:
        nbp=1
        l=suma
        for i in range(k):
            nbp*=C[l][a[i]+1]
            l-=a[i]+1
        res-=nbp
       # print nbp,a
        i=0
        while i<k and a[i]>=v[i]-1:
            i+=1
        if i==k:
            break
        a[i]+=1
        suma+=1
        for j in range(i):
            a[j]=ab[j]
            suma-=v[j]-ab[j]-1
#    ks=d.keys()
#    kv=[d[kk] for kk in ks]
#    
#    for ij in range(len(ks)):
#        it=ks[ij]
#        v=kv[ij]
#        if it:
#            a=[0]*k
#            suma=k
#            a[ij]=-1
#            if v==1:
#                suma-=1
#            ab=a[:]
#            while True:
#                nbp=1
#                l=suma
#                for i in range(k):
#                    nbp*=C[l][a[i]+1]
#                    print [l],[a[i]+1],nbp
#                    l-=a[i]+1
#                res+=nbp
#                print it,nd,nbp,a,v,suma
#                i=0
#                while i<k and a[i]==v[i]-1:
#                    i+=1
#                if i==k:
#                    break
#                a[i]+=1
#                suma+=1
#                for j in range(i):
#                    a[j]=ab[j]
#                    suma-=v[j]-ab[j]-1
#            
    
    
print res