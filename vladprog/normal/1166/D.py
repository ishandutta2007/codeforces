for _ in range(int(input())):
    a,b,m=map(int,input().split())
    if a==b:
        print(1,a)
        continue
    for k in range(2,51):
        pw=1<<(k-2)
        mn=pw*(a+1)
        mx=pw*(a+m)
        if mn<=b<=mx:
            r=[0]*(k+1)
            add=b-mn
            r[1]=a
            for i in range(2,k):
                r[i]=min(m-1,add//(1<<(k-i-1)))
                add-=r[i]*(1<<(k-i-1))
                r[i]+=1
            r[k]=add+1
            x=[0]*(k+1)
            s=0
            for i in range(1,k+1):
                x[i]=s+r[i]
                s+=x[i]
            print(k,*(x[1:]),sep=' ')
            break
    else:
        print(-1)