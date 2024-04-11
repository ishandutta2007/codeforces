x,y=map(int,raw_input().split())
hx,hy,i,x,y,r,tx,ty=[1,0,-1,0],[0,1,0,-1],0,100+x,100+y,0,100,100
a=[[0 for _ in range(1000)]for __ in range(1000)]
while (tx!=x)|(ty!=y):
    a[tx][ty]=1;
    tx,ty=tx+hx[i],ty+hy[i]
    j=(i+1)%4
    if (tx==x)&(ty==y):break
    if (a[tx+hx[j]][ty+hy[j]]!=1):
        i,r=j,r+1
print r