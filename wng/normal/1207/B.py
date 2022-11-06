n,m=[int(k) for k in input().split(" ")]
a=[]
for i in range(n):
    a+=[[int(k) for k in input().split(" ")]]

done=[[0 for j in range(m)] for i in range(n)]

res=[]

def isgood(i,j):
    global done
    global res
    for ot in ((i-1,j-1),(i+1,j+1),(i-1,j+1),(i+1,j-1)):
        ii,jj=ot
        if min(ii,jj)>=0 and ii<n and jj<m and a[ii][jj]:
            if a[i][j] and a[ii][j] and a[i][jj]:
                done[i][j]=1
                done[ii][jj]=1
                done[i][jj]=1
                done[ii][j]=1
                res+=[(min(i,ii),min(j,jj))]
                return True
    return False

isok=True
for i in range(n):
    for j in range(m):
        if a[i][j] and not done[i][j]:
            if not isgood(i,j):
                isok=False
                break
    if not isok:
        break

if isok:
    print(len(res))
    for j in res:
        print(j[0]+1,j[1]+1)
else:
    print(-1)