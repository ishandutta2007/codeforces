n,k=map(int,input().split())
strings=[]
for i in range(n):
    strings.append(input())
minswap=[]
if strings[0][0]=="a":
    minswap.append([0])
else:
    minswap.append([1])
for i in range(n-1):
    new=[]
    if strings[0][i+1]=="a":
        new.append(minswap[-1][0])
    else:
        new.append(minswap[-1][0]+1)
    for j in range(i):
        if strings[j+1][i-j]=="a":
            new.append(min(minswap[-1][j+1],minswap[-1][j]))
        else:
            new.append(min(minswap[-1][j+1],minswap[-1][j])+1)
    if strings[i+1][0]=="a":
        new.append(minswap[-1][-1])
    else:
        new.append(minswap[-1][-1]+1)
    minswap.append(new)
for i in range(n-1):
    new=[]
    for j in range(n-1-i):
        if strings[i+j+1][n-j-1]=="a":
            new.append(min(minswap[-1][j],minswap[-1][j+1]))
        else:
            new.append(min(minswap[-1][j],minswap[-1][j+1])+1)
    minswap.append(new)
farthest=-2
for i in range(2*n-1):
    reach=False
    for guy in minswap[i]:
        if guy<=k:
            reach=True
            break
    if not reach:
        farthest=i-1
        break
if farthest==-2:
    farthest=2*n-2
gis=[]
if farthest>=0:
    out="a"*(farthest+1)
    row=farthest+1 
    for i in range(len(minswap[row-1])):
        if minswap[row-1][i]==k:
            gis.append(i)
else:
    out=strings[0][0]
    row=1
    gis=[0]
while row<2*n-1:
    if row<n:
        letters=[]
        for index in gis:
            letters.append(strings[index][row-index])
            letters.append(strings[index+1][row-index-1])
        low=min(letters)
        newgis=[]
        for index in gis:
            if strings[index][row-index]==low:
                newgis.append(index)
            if strings[index+1][row-index-1]==low:
                newgis.append(index+1)
        out+=low
        gis=list(set(newgis))
        row+=1
    else:
        letters=[]
        for index in gis:
            if index not in {0,2*n-1-row}:
                letters.append(strings[row+index-n][n-index])
                letters.append(strings[row+index+1-n][n-1-index])
            elif index==0:
                letters.append(strings[row+1-n][-1])
            else:
                letters.append(strings[-1][row+1-n])
        low=min(letters)
        newgis=[]
        for index in gis:
            if index not in {0,2*n-1-row}:
                if strings[row+index-n][n-index]==low:
                    newgis.append(index-1)
                if strings[row+index+1-n][n-1-index]==low:
                    newgis.append(index)
            elif index==0:
                if strings[row+1-n][-1]==low:
                    newgis.append(index)
            else:
                if strings[-1][row+1-n]==low:
                    newgis.append(index-1)
        out+=low
        gis=list(set(newgis))
        row+=1
print(out)