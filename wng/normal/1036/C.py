#[int(k) for k in raw_input().split(" ")]

C=[[0 for j in range(50+3)] for i in range(50)]
C[0][0]=1

for i in range(1,50):
    for j in range(i+1):
        C[i][j]=C[i-1][j]+C[i-1][j-1]



def a(n,k): #numbers with n digits of which exactly k are not 0
    if not k:
        return 1
    if k>n:
        return 0
    return C[n][k]*(9**k)

A=[[a(i,j) for j in range(4)] for i in range(20)]


def b(sn,k):
    ln=len(sn)
    #print sn,ln,k
    if sn[0]!="0":
        return A[ln-1][k]+ (((int(sn[0])-1)*A[ln-1][k-1]+ (b(sn[1:],k-1) if ln>1 else (1 if k==1 else 0))) if k>0 else 0)
    else:
        return b(sn[1:],k) if ln>1 else (1 if not k else 0)

q=[int(k) for k in raw_input().split(" ")][0]
for i in range(q):
    l,r=[int(k) for k in raw_input().split(" ")]
    sl=str(l-1)
    rl=b(sl,3)+b(sl,2)+b(sl,1)
    sr=str(r)
    rr=b(sr,3)+b(sr,2)+b(sr,1)
    print rr-rl


##def nbd(n):
##    if not n:
##        return 0
##    if n%10:
##        return 1+nbd(n/10)
##    else:
##        return nbd(n/10)
##
##nbm3=0
##for i in range(1,100000):
##    nbm3+=1 if nbd(i)<=3 else 0
##    assert(nbm3==b(str(i),3)+b(str(i),2)+b(str(i),1))
##    #print nbm3,b(str(i),3)+b(str(i),2)+b(str(i),1)