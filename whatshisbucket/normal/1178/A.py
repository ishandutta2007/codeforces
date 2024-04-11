n=int(input())
a=list(map(int,input().split()))
tot=sum(a)
maj=(tot+2)//2
alice=a[0]
usable=a[0]
for guy in a:
    if 2*guy<=alice:
        usable+=guy
if usable<maj:
    print(0)
else:
    parties=["1"]
    for i in range(n):
        if 2*a[i]<=alice:
            parties.append(str(i+1))
    print(len(parties))
    print(" ".join(parties))