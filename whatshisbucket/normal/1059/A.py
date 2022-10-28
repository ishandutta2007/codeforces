n,L,a=map(int,input().split())
if n==0:
    print(L//a)
else:
    tot=0
    x,y=map(int,input().split())
    tot+=x//a
    end=x+y
    for i in range(n-1):
        x,y=map(int,input().split())
        tot+=(x-end)//a
        end=x+y
    tot+=(L-end)//a
    print(tot)