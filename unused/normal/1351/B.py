for _ in range(int(input())):
    a,b=map(int,input().split())
    c,d=map(int,input().split())
    if a==c and b+d==a or a==d and b+c==a or b==c and a+d==b or b==d and a+c==b:
        print('Yes')
    else:
        print('No')