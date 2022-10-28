n=int(input())
lefts=[]
rights=[]
either=0
for i in range(n):
    s=input()
    partial=0
    maxi=0
    mini=0
    left,right=True,True
    for char in s:
        if char=="(":
            partial+=1
        else:
            partial-=1
            mini=min(partial,mini)
    if mini<0:
        left=False
    if mini<partial:
        right=False
    if left:
        if right:
            either+=1
        else:
            lefts.append(partial)
    elif right:
        rights.append(-partial)
lefts.sort(reverse=True)
rights.sort(reverse=True)
if len(lefts)>0 and len(rights)>0:
    k=max(lefts[0],rights[0])
    lcounts=[0]*(k+1)
    rcounts=[0]*(k+1)
    for guy in lefts:
        lcounts[guy]+=1
    for guy in rights:
        rcounts[guy]+=1
    sumi=0
    for i in range(k+1):
        sumi+=min(lcounts[i],rcounts[i])
    b=abs(lcounts[0]-rcounts[0])
    if b>=either:
        sumi+=either
    else:
        sumi+=b+(either-b)//2
    print(sumi)
else:
    if len(lefts)>0:
        a=lefts.count(0)
    else:
        a=rights.count(0) 
    if a>=either:
        print(either)
    else:
        print(a+(either-a)//2)