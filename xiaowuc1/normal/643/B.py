n, k = (int(x) for x in raw_input().split())
if n == 4 or k <= n:
    print "-1"
else:
    a, b, c, d = (int(x) for x in raw_input().split())
    l = [str(x) for x in range(1, n+1) if x not in [a, b, c, d]]
    print "{} {} {} {} {}".format(a, c, " ".join(l), d, b)
    print "{} {} {} {} {}".format(c, a, " ".join(l), b, d)