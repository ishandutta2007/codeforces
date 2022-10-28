t=int(input())
for i in range(t):
    n,m=map(int,input().split())
    x1,y1,x2,y2=map(int,input().split())
    x3,y3,x4,y4=map(int,input().split())
    init_b=m*n//2
    init_w=m*n-init_b
    l,w=x2-x1+1,y2-y1+1
    if (x1+y1)%2==0:
        w1=init_w+l*w//2
        b1=init_b-l*w//2
    else:
        w1=init_w+(l*w-l*w//2)
        b1=init_b-(l*w-l*w//2)
    l,w=x4-x3+1,y4-y3+1
    if (x3+y3)%2==0:
        w2=w1-(l*w-l*w//2)
        b2=b1+(l*w-l*w//2)
    else:
        w2=w1-l*w//2
        b2=b1+l*w//2
    bot=max((y1,y3))
    top=min((y2,y4))
    left=max((x1,x3))
    right=min((x2,x4))
    if bot>top or left>right:
        print(w2,b2)
        continue
    l,w=right-left+1,top-bot+1
    if (bot+left)%2==0:
        w3=w2-l*w//2
        b3=b2+l*w//2
    else:
        w3=w2-(l*w-l*w//2)
        b3=b2+(l*w-l*w//2)
    print(w3,b3)