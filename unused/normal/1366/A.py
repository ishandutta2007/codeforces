for _ in range(int(input())):
    a,b=map(int,input().split())
    if a<b:
        a,b=b,a
    if a>b*2:
        a=b*2
    print(a-b+(b-(a-b))*2//3)