n,m=map(int,input().split())
a=list(map(int,input().split()))
sml=0
big=m-1
curr=(m-1)//2
while sml!=big:
    bug=0
    good=True
    for i in range(n):
        if a[i]+curr<m+bug:
            if a[i]+curr<bug:
                good=False
                break
            bug=max(bug,a[i])
    if good:
        big=max(curr,sml)
        curr=(big+sml)//2
    else:
        sml=min(curr+1,big)
        curr=(sml+big)//2
print(curr)