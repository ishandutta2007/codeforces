n=int(input())
if n==1:
    print(1)
else:
    p=list(map(int,input().split()))
    children=[]
    for i in range(n):
        children.append([])
    for i in range(n-1):
        children[p[i]-1].append(i+1)
    layers=[1]+[0]*(n-1)
    layer=[0]
    num=2
    bylayer=[]
    while len(layer)>0:
        bylayer.append(layer)
        newlayer=[]
        for vert in layer:
            for child in children[vert]:
                layers[child]=num
                newlayer.append(child)
        layer=newlayer
        num+=1
    bylayer=bylayer[::-1]
    count=[0]*n
    for layer in bylayer:
        for vert in layer:
            if children[vert]==[]:
                count[vert]=1
            else:
                count[vert]=sum(count[v] for v in children[vert])
    count.sort()
    out=""
    for guy in count:
        out+=str(guy)+" "
    print(out)