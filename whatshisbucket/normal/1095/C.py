n,k=map(int,input().split())
if k>n or k<bin(n)[2:].count("1"):
    print("NO")
else:
    print("YES")
    a=bin(n)[2:][::-1]
    ind=0
    powers=[]
    for char in a:
        if char=="1":
            powers.append(2**ind)
        ind+=1
    ind=0
    tot=len(powers)
    while tot<k:
        if powers[ind]>1:
            powers[ind]//=2
            powers.append(powers[ind])
            tot+=1
        else:
            ind+=1
    out=""
    for guy in powers:
        out+=str(guy)+" "
    print(out)