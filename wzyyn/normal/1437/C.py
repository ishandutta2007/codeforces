import array

def Abs(x):
    if x<0:
        return -x
    return x

def solve():
    n=int(input())
    a=array.array('i',map(int,input().split()))
    b=array.array('i',[0 for i in range(3*n)])
    c=array.array('i',[1<<30 for i in range(3*n)])
    c[0]=0
    for i in range(n):
        b[a[i]+n]+=1
    for i in range(1,3*n):
        b[i]+=b[i-1]
    for i in range(n+1,3*n):
        for j in range(n,0,-1):
            c[j]=min(c[j],c[j-1])
        for j in range(n+1):
            c[j]+=Abs(j-b[i])
        #print(i,c[n])
    print(c[n])

T=int(input())
for Tid in range(T):
    solve()