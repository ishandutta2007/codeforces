n,m=map(int,input().split())
vert=[]
for i in range(n):
    vert.append(int(input()))
horiz=[]
for i in range(m):
    a,b,c=map(int,input().split())
    if a==1:
        horiz.append(b)
vert.sort()
vert.append(1000000000)
vert.append(2000000000)
horiz.sort()
oof=[0]*(n+2)
b=0
for i in range(len(horiz)):
    while True:
        if horiz[i]<vert[b]:
            oof[b]+=1
            break
        else:
            b+=1
mini=1000000
bad=len(horiz)
for i in range(n+1):
    bad-=oof[i]
    if bad+i<mini:
        mini=bad+i
print(mini)