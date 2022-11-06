d=int(raw_input())
n,m =[int(k) for k in raw_input().split(" ")]
sofas=[0]*d
tblr=[0]*4
stblr=[0]*4
for i in range(4):
    tblr[i]=[0]*(n+1 if i<2 else m+1)
    stblr[i]=[0]*(n+1 if i<2 else m+1)
for i in range(d):
    x,y,z,tt=[int(k) for k in raw_input().split(" ")]
    r=max(x,z)
    l=x+z-r
    b=max(y,tt)
    t=y+tt-b
    sofas[i]=(r,l,b,t)
    tblr[0][r]+=1
    tblr[1][l]+=1
    tblr[2][b]+=1
    tblr[3][t]+=1
cl,cr,ct,cb=[int(k) for k in raw_input().split(" ")]

stblr[0][0]=0#tblr[0][0]
stblr[2][0]=0#tblr[2][0]
stblr[1][-1]=0#tblr[1][-1]
stblr[3][-1]=0#tblr[3][-1]

for i in range(1,n):
    stblr[1][i+1]=stblr[1][i]+tblr[1][i]
    stblr[0][n-i]=stblr[0][n-i+1]+tblr[0][n-i+1]
    
for i in range(1,m):
    stblr[3][i+1]=stblr[3][i]+tblr[3][i]
    stblr[2][m-i]=stblr[2][m-i+1]+tblr[2][m-i+1]

res=-1
for i in range(d):
    xx,nx,xy,ny=sofas[i]
    tblrdusof=[stblr[0][nx]- (1 if xx>nx else 0),stblr[1][xx]- (1 if xx>nx else 0),stblr[2][ny]-(1 if xy>ny else 0),stblr[3][xy]-(1 if xy>ny else 0)]
   # print i,tblrdusof
    if tblrdusof[0]==cr and tblrdusof[1]==cl and tblrdusof[2]==cb and tblrdusof[3]==ct:
        res=i+1
        break

print res