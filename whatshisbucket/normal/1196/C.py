
q=int(input())
for _ in range(q):
    n=int(input())
    bot=left=-100000
    top=right=100000
    for i in range(n):
        x,y,l,u,r,d=map(int,input().split())
        if l==0:
            left=max(left,x)
        if r==0:
            right=min(right,x)
        if u==0:
            top=min(top,y)
        if d==0:
            bot=max(bot,y)
    if top>=bot and right>=left:
        print(1,left,bot)
    else:
        print(0)