import array
T=int(input())
for i in range(T):
    ans=0
    n=int(input())
    a=array.array('i',map(int,input().split()))
    f,s=0,0
    for i in range(n):
        if a[i]==1:
            ans=ans+s
            f=1
            s=0
        else:
            s=s+f
    print(ans)