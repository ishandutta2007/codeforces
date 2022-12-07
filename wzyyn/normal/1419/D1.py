T=1
for Tid in range(T):
    n=int(input())
    a=list(map(int,input().split()))
    a.sort()
    b=[]
    p1=0
    p2=n//2;
    print((n-1)//2)
    for i in range(n):
        if (i%2==0):
            x=a[p2]
            p2=p2+1
        else:
            x=a[p1]
            p1=p1+1
        if (i==n-1):
            print(x)
        else:
            print(x,end=' ')