
t=int(input())
for nt in range(t):
    c,s=[int(k) for k in input().strip().split(" ")]
    res=0
    nba= s//c
    nbap=nba+1
    np= s%c
    na= c-np
    print(np*nbap*nbap + na *nba*nba)