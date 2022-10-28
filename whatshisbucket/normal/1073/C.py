n=int(input())
a=input()
x,y=map(int,input().split())
locs=[(0,0)]
for i in range(n):
    if a[i]=="U":
        locs.append((locs[-1][0],locs[-1][1]+1))
    elif a[i]=="D":
        locs.append((locs[-1][0],locs[-1][1]-1))
    elif a[i]=="R":
        locs.append((locs[-1][0]+1,locs[-1][1]))
    else:
        locs.append((locs[-1][0]-1,locs[-1][1]))
if abs(x)+abs(y)>n or (x+y-n)%2==1:
    print(-1)
elif locs[-1]==(x,y):
    print(0)
else:
    a=0
    b=0
    best=n
    end=locs[-1]
    while True:
        c,d=locs[a][0]+end[0]-locs[b][0],locs[a][1]+end[1]-locs[b][1]
        if abs(c-x)+abs(d-y)<=b-a:
            best=min(best,b-a)
            a+=1
        else:
            b+=1
            if b>n:
                print(best)
                break