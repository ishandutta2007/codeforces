n,m=[int(k) for k in raw_input().split(" ")]

if m>n:
    m,n=n,m

if m>=3:
    if (m*n)%2:
        print m*n-1
    else:
        print m*n
elif m==2:
    if n==2:
        print 0
    elif n==3:
        print 4
    elif n==7:
        print 12
    else:
        print n*m
else:
    n6=n%6
    nn=(n/6)*6
    if n6==5:
        nn+=4
    if n6==4:
        nn+=2
    print nn