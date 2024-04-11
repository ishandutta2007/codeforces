for _ in range(int(input())):
    a,b,c,d = map(int,input().split())
    a,b,c,d = sorted([a,b,c,d])
    print(a*c)