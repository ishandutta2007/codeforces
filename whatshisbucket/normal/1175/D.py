n,k=map(int,input().split())
a=list(map(int,input().split()))
if n==1:
    print(a[0])
else:
    p=[a[-1]]+[0]*(n-2)
    for i in range(n-2):
        p[i+1]=p[i]+a[-i-2]
    j=p[-1]+a[0]
    p.sort(reverse=True)
    print(j+sum(p[:k-1]))