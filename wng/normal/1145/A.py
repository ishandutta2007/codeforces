n=int(input())
a=[int(k) for k in input().split(" ")]

nn=n

res=1
while nn>1:
    jj=0
    while jj<n:
        if sorted(a[jj:jj+nn])==a[jj:jj+nn]:
            res=nn
            break
        jj+=nn
    if res>=nn:
        break
    nn>>=1
    
print(res)