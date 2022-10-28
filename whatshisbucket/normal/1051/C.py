n=int(input())
a=list(map(int,input().split()))
counts=[0]*101
for guy in a:
    counts[guy]+=1
useless=counts.count(0)+counts.count(2)
forced=counts.count(1)
useful=101-useless-forced
if useful==0 and forced%2==1:
    print("NO")
else:
    if forced%2==0:
        each=forced//2
        out=""
        seen=0
        for guy in a:
            if counts[guy]==1 and seen<each:
                out+="A"
                seen+=1
            else:
                out+="B"
    else:
        As=forced//2
        out=""
        seen=0
        good=0
        for guy in a:
            if counts[guy]==1 and seen<As:
                out+="A"
                seen+=1
            elif counts[guy]>2 and good==0:
                out+="A"
                good=1
            else:
                out+="B"
    print("YES")
    print(out)