T = int (input())
while T > 0:
    T -= 1
    S = input().split()
    a = [int (x) for x in S]
    n = a[0]
    m = a[1]
    S = input().split()
    a = [int (x) for x in S]
    minx = a[0]
    maxx = a[0]
    ans = 0
    for x in a:
        if minx > x:
            minx = x
        if maxx < x:
            maxx = x
        if maxx - minx > m+m:
            ans+=1
            maxx = x
            minx = x
    print (ans)