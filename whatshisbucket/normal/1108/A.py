q=int(input())
for i in range(q):
    a,b,c,d=map(int,input().split())
    if a==b:
        if c==a:
            print(a,d)
        else:
            print(a,c)
    elif c==d:
        if c==a:
            print(b,c)
        else:
            print(a,c)
    elif a==d:
        print(a,c)
    else:
        print(a,d)