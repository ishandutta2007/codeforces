T=int(input())
for Tid in range(T):
    n,m=map(int,input().split())
    a=[]
    for i in range(n):
        a.append(list(map(int,input().split())))
    ans=0
    for i in range((n+1)//2):
        for j in range((m+1)//2):
            b=[]
            b.append(a[i][j])
            if n-i-1!=i:
                b.append(a[n-i-1][j])
            if m-j-1!=j:
                b.append(a[i][m-1-j])
                if n-i-1!=i:
                    b.append(a[n-i-1][m-1-j])
            b=sorted(b)
            l=len(b)
            # print(b)
            for k in range(l//2):
                ans=ans+b[l-1-k]-b[k]
    print(ans)