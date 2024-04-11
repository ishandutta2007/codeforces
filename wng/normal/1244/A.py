t=[int(k) for k in input().split(" ")][0]
for nt in range(t):
    a,b,c,d,k=[int(k) for k in input().split(" ")]
    cp=(a-1)//c+1
    dp=(b-1)//d+1
    if (cp+dp)<=k:
        print(cp,dp)
    else:
        print("-1")