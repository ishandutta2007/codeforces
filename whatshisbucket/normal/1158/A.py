n,m=map(int,input().split())
b=list(map(int,input().split()))
g=list(map(int,input().split()))
if max(b)>min(g):
    print(-1)
else:
    maxi=0
    maxi2=0
    for guy in b:
        if guy>maxi:
            maxi2,maxi=maxi,guy
        elif guy>maxi2:
            maxi2=guy
    sumi=m*sum(b)+sum(g)-m*maxi+maxi-maxi2
    if maxi in g:
        sumi-=(maxi-maxi2)
    print(sumi)