n=int(input())
for i in range(n):
    l,r=map(int,input().split())
    if(l%2==1 and r%2==1):
        print(-l-(r-l)//2)
    elif(l%2==0 and r%2==1):
        print(-(r-l+1)//2)
    elif(l%2==0 and r%2==0):
        print(l+(r-l)//2)
    else:
        print((r-l+1)//2)