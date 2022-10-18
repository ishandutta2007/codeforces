R=lambda:map(int,input().split())
n,m=R()
if n<3 or m<9:
    print(-1)
    exit()
a=[[0]*(n-2) for i in range(n-2)]
for i in range(1,m+1):
    x,y=R()
    x-=1
    y-=1
    for x0 in range(x-2,x+1):
        for y0 in range(y-2,y+1):
            if x0<0 or y0<0 or x0>=n-2 or y0>=n-2:
                continue
            a[x0][y0]+=1
            if a[x0][y0]==9:
                print(i)
                exit()
print(-1)