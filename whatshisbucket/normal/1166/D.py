q=int(input())
for u in range(q):
    a,b,m=map(int,input().split())
    ranges=[(a,a)]
    bigsum=a
    smlsum=a
    while ranges[-1][1]<b:
        ranges.append((smlsum+1,bigsum+m))
        smlsum=2*smlsum+1
        bigsum=2*bigsum+m
    if b<ranges[-1][0]:
        print(-1)
    else:
        seq=[a]
        leng=len(ranges)
        power=2**(leng-3)
        curr=(a+1)*(2**(leng-2))
        sumi=a
        for i in range(leng-2):
            seq.append(sumi+max(min((b-curr)//power+1,m),1))
            power//=2
            sumi+=seq[-1]
            curr=(sumi+1)*(2**(leng-i-3))
        if b!=seq[-1]:
            seq.append(b)
        out=[leng]+seq
        out=[str(guy) for guy in out]
        print(" ".join(out))