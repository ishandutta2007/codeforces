import math
n,k=map(int,input().split())
edges=[]
for i in range(n-1):
    edges.append(tuple(map(int,input().split())))
degreelist=[]
for i in range(min(k+1,math.floor(math.log2(n))+10)):
    degreelist.append({})
degrees=degreelist[0]
for i in range(1,n+1):
    degrees[i]=0
for guy in edges:
    degrees[guy[0]]+=1
    degrees[guy[1]]+=1
small=[]
center=None
done=False
for i in range(k):
    if not done:
        small=[]
        for guy in degrees:
            if degrees[guy]==2:
                print("No")
                done=True
                break
            if degrees[guy]==3:
                small.append(guy)
                if center==None: 
                    center=guy
                elif center!=guy:
                    print("No")
                    done=True
                    break
            elif degrees[guy]>1:
                small.append(guy)
        degrees=degreelist[i+1]
        if center!=None and center not in small:
            if not done:
                print("No")
            done=True
            break
        elif len(small)==0:
            if not done:
                print("No")
            done=True
            break
        for guy in small:
            degrees[guy]=0
        for guy in edges:
            if guy[0] in degrees and guy[1] in degrees:
                degrees[guy[0]]+=1
                degrees[guy[1]]+=1
        for guy in degrees:
            if degrees[guy]>1 and degreelist[i][guy]!=degrees[guy]:
                if not done:
                    print("No")
                done=True
                break
    else:
        break
if not done:
    if len(degreelist[-1])==1:
        print("Yes")
    else:
        print("No")