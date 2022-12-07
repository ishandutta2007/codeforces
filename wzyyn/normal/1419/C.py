T=int(input())
for Tid in range(T):
    n,x=map(int,input().split())
    s=-1*n*x
    a=list(map(int,input().split()))
    flag=1
    flag1=0
    for i in range(n):
        if (a[i]!=x):
            flag=0
        else:
            flag1=1
        s=s+a[i]
    if flag:
        print(0)
    else:
        if s==0 or flag1==1:
            print(1)
        else:
            print(2)