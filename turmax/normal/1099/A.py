m,n=map(int,input().split())
x1,y1=map(int,input().split())
x2,y2=map(int,input().split())
v=m
for i in range(n,0,(-1)):
    v+=i
    if(y1==i):
        v-=x1
    if(y2==i):
        v-=x2
    if(v<0):
        v=0
print(v)