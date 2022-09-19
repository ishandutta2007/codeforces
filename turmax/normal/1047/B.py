n=int(input())
t=0
for a in range(n):
    x,y=map(int,input().split())
    a=x+y
    if(a>t):
        t=a
print(t)