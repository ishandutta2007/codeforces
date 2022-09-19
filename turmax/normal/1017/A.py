a=int(input())
t=[]
for i in range(0,a):
    b,c,d,e=map(int,input().split())
    t.append(b+c+d+e)
x=1
for j in range(1,len(t)):
    if(t[j]>t[0]):
        x+=1
print(x)