def main():
    R=lambda:map(int,input().split())
    n,k=R()
    a=list(R())
    m=n//k
    ans=0
    for i in range(k):
        c=[n,0,0]
        for j in range(m):
            c[a[j*k+i]]+=1
        ans+=min(c)
    print(ans)

main()