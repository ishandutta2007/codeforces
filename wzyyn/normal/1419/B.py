T=int(input())
for Tid in range(T):
    n=int(input())
    t=1
    ans=0
    while n>=t*(t+1)//2:
        n=n-t*(t+1)//2
        ans=ans+1
        t=t*2+1
    print(ans)