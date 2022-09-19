n,x,y=map(int,input().split())
a=list(map(int,input().split()))
if(x>y):
    print(n)
    exit(0)
else:
    t=0
    for i in a:
        if(i<=x):
            t+=1
    print((t+1)//2)