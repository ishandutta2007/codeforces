n,m,k=map(int,raw_input().split())

if k == 1 or (n % 2 == m % 2):
    print pow(2, (n - 1) * (m - 1), 1000000007)
else:
    print 0