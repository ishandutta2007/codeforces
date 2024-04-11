#[int(k) for k in raw_input().split(" ")]
o=raw_input()
i=raw_input()
so=sorted(o)
si=sorted(i,reverse=True)
res=[None]*len(o)

n=len(o)
k=0
lefti=n/2
lefto=n-lefti
ke=lefto-1
ki=0
kei=lefti-1
who=1
j=0
je=n-1
while j<=je:
    if who:
        if so[k]<si[ki]: #Your best beats his best
            res[j]=so[k]
            j+=1
            k+=1
        else:
            res[je]=so[ke]
            je-=1
            ke-=1
    else:
        if so[k]<si[ki]: #Your best beats his best
            res[j]=si[ki]
            j+=1
            ki+=1
        else:
            res[je]=si[kei]
            je-=1
            kei-=1
    who=1-who

print "".join(res)