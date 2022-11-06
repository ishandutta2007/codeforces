n,m=[int(i) for i in raw_input().split(" ")]

g=[0]*n
gg=[0]*n
gg0=[0]*n
res=0
ress=""
for k in range(n):
    g[k]=[int(i) for i in raw_input().split(" ")];
word1="col"
word2="row"
if n>m:
    
    h=[0]*m
    for i in range(m):
        h[i]=[g[k][i] for k in range(n)]
    g=h
    mm=n
    n=m
    m=mm
    word2="col"
    word1="row"

for k in range(n):
    if res!=-1:
        mg=min(g[k])    
        gg[k]=[i-mg for i in g[k]]
        res+=mg
        if k==0:
            res+=sum(gg[k])
            for i in range(m):
                ress+="{} {}\n".format(word1,i+1)*gg[k][i]
        else:
            for i in range(m):
                if gg[k][i]!=gg[0][i]:
                    res=-1
                    break
        ress+="{} {}\n".format(word2,k+1)*mg
print res
if res!=-1:
    print ress[:-1]