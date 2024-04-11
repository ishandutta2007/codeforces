q=int(input())
for i in range(q):
    a,b=map(int,input().split())
    if a%2==0:
        if b%2==0:
            print((b+a)//2)
        else:
            print(-(b-a+1)//2)
    else:
        if b%2==1:
            print(-(b+a)//2)
        else:
            print((b-a+1)//2)