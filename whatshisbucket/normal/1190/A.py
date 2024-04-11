n,m,k=map(int,input().split())
p=list(map(int,input().split()))
p=[p[i]-1 for i in range(m)]
page=[(p[i]-i)//k for i in range(m)]
same=0
pos=[0]*m
for i in range(m):
    if i>0:
        if page[i]==page[i-1]:
            same+=1
        else:
            same=0
    pos[i]=(p[i]-i)%k+same
curr=page[0]
pages=[[]]
for i in range(m):
    if page[i]==curr:
        pages[-1].append(pos[i])
    else:
        curr=page[i]
        pages.append([pos[i]])
tot=0
for page in pages:
    a=len(page)
    ind=0
    end=k
    steps=1
    while ind<a:
        if page[ind]>=end:
            end=k+ind
            steps+=1
        ind+=1
    tot+=steps
print(tot)