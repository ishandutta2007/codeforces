n, m = (int(x) for x in raw_input().split())
print "{} {}".format(min(m,n), (max(m,n)-min(m,n))/2)