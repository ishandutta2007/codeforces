t=int(input())
for i in range (t):
    n, m=input().split()
    n=int(n);
    m=int(m);
    a=[0]*n
    p=[0]*n
    a=input().split()
    for j in range(n):
        p[int(a[j])-1]=j
    mx=-1
    ans=0
    b=[0]*n;
    b=input().split()
    for j in range(m):
        b[j]=p[int(b[j])-1]
        if mx<b[j] :
            mx=b[j]
            ans+=(b[j]-j)*2+1;
        else:
            ans+=1
    print(ans)