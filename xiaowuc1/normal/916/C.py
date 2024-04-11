def prime(x):
    i = 2
    while i * i <= x:
        if x%i == 0:
            return False
        i += 1
    return True

n, m = (int(x) for x in raw_input().split())
want = max(2, n-1)
while not prime(want):
    want += 1
print "{} {}".format(want, want)
for i in xrange(n-1):
    if i == n-2:
        print "{} {} {}".format(i+1, i+2, want)
    else:
        print "{} {} {}".format(i+1, i+2, 1)
        want -= 1
    m -= 1
diff = 2
i = 1
while m:
    if i + diff > n:
        i = 1
        diff += 1
    print "{} {} {}".format(i, i+diff, 1000000000)
    i += 1
    m -= 1