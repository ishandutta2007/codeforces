for T in range(int(input())):
    n,x,m=map(int,input().split())
    l=r=x
    for I in range(m):
        a,b=map(int,input().split())
        if r<a or b<l:
            continue
        l=min(l,a)
        r=max(r,b)
    print(r-l+1)