n,k=map(int,input().split())
a=list(map(int,input().split()))
big=sum(a)
if big%k!=0:
    print("No")
else:
    j=big//k
    curr=0
    vids=0
    lens=[]
    for guy in a:
        curr+=guy
        vids+=1
        if curr==j:
            lens.append(vids)
            curr=0
            vids=0
        elif curr>j:
            print("No")
            break
    if len(lens)==k:
        out=""
        for guy in lens:
            out+=str(guy)+" "
        print("Yes")
        print(out)