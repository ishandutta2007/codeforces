t=int(input())
for nt in range(t):
    b,p,f=[int(k) for k in input().split(" ")]
    h,c=[int(k) for k in input().split(" ")]
    if c>h:
        c,h=h,c
        p,f=f,p
    res=0
    nbmx=min(b//2,p)
    b-=nbmx*2
    nbmn=min(b//2,f)
    res=nbmx*h+nbmn*c
    print(res)