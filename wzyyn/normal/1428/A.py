T=int(input())
for Tid in range(T):
    x1,y1,x2,y2=map(int,input().split())
    def F(delta):
        if delta<0:
            return -delta
        return delta
    ans=F(x1-x2)+F(y1-y2)
    if x1!=x2 and y1!=y2:
        ans+=2
    print(ans)