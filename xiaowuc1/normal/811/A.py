(a, b) = (int(x) for x in raw_input().split())
c = 1
d = 2
done = False
while not done:
    if c > a:
        print "Vladik"
        done = True
    elif d > b:
        print "Valera"
        done = True
    else:
        a -= c
        b -= d
        c += 2
        d += 2