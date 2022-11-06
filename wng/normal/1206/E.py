from sys import stdout




# matrix="""
# 101110111011101110111
# 011101110111011101110
# 111011101110111011101
# 110111011101110111011
# 101110111011101110111
# 011101110111011101110
# 111011101110111011101
# 110111011101110111011
# 101110111011101110111
# 011101110111011101110
# 111011101110111011100
# 110111011101110111001
# 101110111011101110010
# 011101110111011100100
# 111011101110111001000
# 110111011101110010001
# 101110111011100100010
# 011101110111001000100
# 111011101110010001000
# 110111011100100010001
# 101110111001000100010"""
#m=matrix.split()
n=int(input())#len(m)#

def query(i,j,k,l):
    print("? {} {} {} {}".format(i,j,k,l))
    if (k+l-i-j)==2:
        res=1 if m[i-1][j-1]==m[k-1][l-1] else 0
    if (k+l-i-j)==3:#la forme doit etre rect
        assert k>i and l>j
        isok=(a[i-1][j-1]==a[k-1][l-1])
        if isok:
            lautre= (m[k-2][j-1]==m[k-1][j-1]) if (k-i==2) else (m[i-1][l-1]==m[i-1][l-2])
            matchpal= (m[i][j-1]==m[i][j]) or (m[i-1][j]==m[i][j]) or lautre
            isok&=matchpal
        res=1 if isok else 0
    print(res)
    return res  

def req(i,j,k,l):
    print("? {} {} {} {}".format(i,j,k,l))
    stdout.flush()
    rep=int(input())
    return rep


a=[[0 for i in range(n)] for j in range(n)]
a[0][0]=1
a[n-1][n-1]=-1
a[0][1]=2

#a[2][1]
prev=0,1
i=2
j=1

rep=req(prev[0]+1,prev[1]+1,i+1,j+1)
if rep:
    a[i][j]=a[prev[0]][prev[1]]
else:
    a[i][j]=-a[prev[0]][prev[1]]

#a[1][0]
prev=2,1
i=1
j=0
rep=req(i+1,j+1,prev[0]+1,prev[1]+1)
if rep:
    a[i][j]=a[prev[0]][prev[1]]
else:
    a[i][j]=-a[prev[0]][prev[1]]


#on fait le reste
for i in range(n):
    for j in range(n):
        if not a[i][j]:
            prev=(i-1,j-1) if i and j else ((i-2,j) if i else (i,j-2))
            rep=req(prev[0]+1,prev[1]+1,i+1,j+1)
            if rep:
                a[i][j]=a[prev[0]][prev[1]]
            else:
                a[i][j]=-a[prev[0]][prev[1]]
            assert(a[i][j])
            
#on cherche une case paire tq  case +2 +2 est diffrente


baserec=-1,-1
for i in range(n-2):
    for j in range(n-2):
        if (i+j+1)%2 and a[i][j]!=a[i+2][j+2]:
            baserec=i,j
            break
    if baserec[0]!=-1:
        break


assert baserec[0]!=-1

i,j=baserec
#print("baserec",i,j)
rv2=None

#print(a[i][j],a[i][j+1],a[i][j+2])
#print(a[i+1][j],a[i+1][j+1],a[i+1][j+2])
#print(a[i+2][j],a[i+2][j+1],a[i+2][j+2])

if a[i][j+1]==a[i+1][j+2]:
    if a[i+1][j+1]==a[i][j]:
        prev=i,j
        curr=i+1,j+2
        rep=req(prev[0]+1,prev[1]+1,curr[0]+1,curr[1]+1)
        if rep:
            rv2=a[i][j] if a[i][j+1]==2 else -a[i][j]
        else:
            rv2=-a[i][j] if a[i][j+1]==2 else a[i][j]
    else:
        prev=i,j+1
        curr=i+2,j+2
        rep=req(prev[0]+1,prev[1]+1,curr[0]+1,curr[1]+1)
        if rep:
            rv2=a[i+1][j+1] if a[i][j+1]==2 else -a[i+1][j+1]
        else:
            rv2=-a[i+1][j+1] if a[i][j+1]==2 else a[i+1][j+1]
else:
    if a[i+1][j+1]!=a[i][j]:
        prev=i,j
        curr=i+1,j+2
        rep=req(prev[0]+1,prev[1]+1,curr[0]+1,curr[1]+1)
        if rep:
            rv2=a[i+1][j+1] if a[i][j+1]==2 else -a[i+1][j+1]
        else:
            rv2=-a[i+1][j+1] if a[i][j+1]==2 else a[i+1][j+1]
    else:
        prev=i,j+1
        curr=i+2,j+2
        rep=req(prev[0]+1,prev[1]+1,curr[0]+1,curr[1]+1)
        if rep:
            rv2=a[i+1][j+1] if a[i+1][j+2]==2 else -a[i+1][j+1]
        else:
            rv2=-a[i+1][j+1] if a[i+1][j+2]==2 else a[i+1][j+1]
    
for i in range(n):
    for j in range(n):
        if a[i][j] in (-2,2):
            a[i][j]= rv2 if a[i][j]==2 else -rv2

print("!")
for i in range(n):
    r=""
    for j in range(n):
        r+="1" if a[i][j]>0 else "0"
    print(r)
stdout.flush()