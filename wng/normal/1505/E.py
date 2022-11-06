
n,m=[int(i) for i in input().split()]
a=[None]*n
for i in range(n):
    a[i]=[1 if i=="*" else 0 for i in input()]

#print(a)

cc=(0,0)

res=0
curdir=1
while True:
    if a[cc[0]][cc[1]]:
        res+=1
    if cc==(n-1,m-1):
        break
    distright=1000
    if cc[0]==n-1:
        distright=10000
    for j in range(cc[0]+1,n):
        if a[j][cc[1]]:
            distright=j-cc[0]
            break
    distdown=1000
    if cc[1]==m-1:
        distdown=10000
    for j in range(cc[1]+1,m):
        if a[cc[0]][j]:
            distdown=j-cc[1]
            break
    #print(cc, distright, distdown)
    if distright<distdown:
        nxt=(cc[0]+1,cc[1])
    else:
        nxt=(cc[0],cc[1]+1)
    cc=nxt
print(res)