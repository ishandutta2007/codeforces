import math
t=int(input())
for i in range(t):
    n,x,y,d=map(int,input().split())
    if abs(x-y)%d==0:
        print(abs(x-y)//d)
        continue
    if (y-1)%d==0:
        left=True
    else:
        left=False
    if (n-y)%d==0:
        right=True
    else:
        right=False
    if left:
        if right:
            print(min((math.ceil((x-1)/d)+(y-1)//d,math.ceil((n-x)/d)+(n-y)//d)))
        else:
            print(math.ceil((x-1)/d)+(y-1)//d)
        continue
    if right:
        print(math.ceil((n-x)/d)+(n-y)//d)
        continue
    print(-1)