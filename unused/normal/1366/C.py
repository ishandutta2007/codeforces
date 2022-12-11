for _ in range(int(input())):
    n,m=map(int,input().split())
    d=[]
    for _ in range(n):
        d.append(list(map(int,input().split())))
    cnt=[]
    for i in range(n+m-1):
        cnt.append([0]*2)
    for i in range(n):
        for j in range(m):
            cnt[i+j][d[i][j]] += 1
    ans=0
    for i in range(n+m-1):
        if i >= n+m-2-i:
            break
        ans+=min(cnt[i][0]+cnt[-i-1][0],cnt[i][1]+cnt[-i-1][1])
    print(ans)