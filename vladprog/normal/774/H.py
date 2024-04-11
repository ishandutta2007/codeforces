n=int(input())
c=[0]+list(map(int,input().split()))
ans=[]
for i in reversed(range(1,n+1)):
    for x in ans:
        c[i]-=x-i+1
    ans+=[i]*c[i]
a=True
for x in ans:
    print(end=('a' if a else 'b')*x)
    a=not a