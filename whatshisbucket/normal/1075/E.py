n=int(input())
tl=tr=bl=br=top=bot=left=right=-200000000
for i in range(n):
    a,b=map(int,input().split())
    top=max(top,b)
    bot=max(bot,-b)
    right=max(right,a)
    left=max(left,-a)
    tr=max(tr,a+b)
    tl=max(tl,b-a)
    br=max(br,a-b)
    bl=max(bl,-a-b)
print(str(2*max(top+left+br,top+right+bl,bot+left+tr,bot+right+tl))+(n-3)*(" "+str(2*(top+bot+left+right))))