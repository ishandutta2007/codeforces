n,k=[int(k) for k in raw_input().split(" ")]

nbm=2*k+1

if not n%nbm:
    print n/nbm
    print " ".join([str((2*k+1)*i+k+1) for i in range(n/nbm)])
else:
    print n/nbm+1
    lag1=min(k,nbm-(n%nbm))
    lag2=max(0,nbm-(n%nbm)-lag1)
    print " ".join([str((2*k+1)*i+k+1-lag1) for i in range(n/nbm+1)])