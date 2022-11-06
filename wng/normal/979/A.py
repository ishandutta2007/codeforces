n=[int(k) for k in raw_input().split(" ")][0]

if (n+1)%2:
    if n:   
        print n+1
    else:
        print 0
else:
    print (n+1)/2