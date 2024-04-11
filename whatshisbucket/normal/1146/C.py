import math
t=int(input())
for u in range(t):
    n=int(input())
    query=math.ceil(math.log2(n))
    bins=[bin(i+1)[::-1]+"0000000000" for i in range(n)]
    maxi=0
    for i in range(query):
        first=[]
        sec=[]
        for j in range(n):
            if bins[j][i]=="1":
                first.append(str(j+1))
            else:
                sec.append(str(j+1))
        print(str(len(first))+" "+str(len(sec))+" "+" ".join(first)+" "+" ".join(sec))
        k=int(input())
        maxi=max(maxi,k)
    print("-1 "+str(maxi))