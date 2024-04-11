n,t = map(int,input().split())
if n==1 and t==10: print(-1)
else:
    x = 10**(n-1)
    while x%t!=0: x+=1
    print(x)