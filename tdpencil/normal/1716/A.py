t=int(input())
while t > 0:
    t -= 1
    x=int(input())
    ans = 999999999
    if x % 2 == 0:
        ans=min(ans,x//2)
    if x % 3 == 1:
        ans=min(ans,x//3+2)
        if x - 3 >= 2:
            ans=min(ans,(x-3)//3+2)
    if x % 3 == 0:
        ans=min(ans,x//3)
    if x % 3 == 2:
        ans=min(ans,x//3+1)
    print(ans)