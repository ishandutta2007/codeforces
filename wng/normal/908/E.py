
#Nice now I'm sumproduct of gps times bell function
mod=10**9+7
def Blist(m):
    A = [0 for i in range(0, m)]
    A[0] = 1
    R = [1, 1]
    for n in range(1, m):
        A[n] = A[0]
        for k in range(n, 0, -1):
            A[k-1] += A[k]
            A[k-1]%=mod
        R.append(A[0])
    return R
    
    
m,n=[int(k) for k in raw_input().split(" ")]
t=[]
for i in range(n):
    t+=[[k for k in raw_input()]]

ti=[int("".join([t[i][k] for i in range(n)]),2) for k in range(m)]

left=set(range(m))
potes=[]
gps=[]
mxl=0
for k in range(m):
    if k in left:
        totej=set()
        for j in left:
            if ti[k]^ti[j]==0:
                totej.add(j)
        left=left-totej
        gps+=[len(totej)]  
        mxl=max(mxl,len(totej))

bl=Blist(m)

res=1

for k in gps:
    res*=bl[k]
    res%=mod

print res