n,m=map(int,raw_input().split())
print " ".join(map(str,[n/m+(i<n%m) for i in range(m)]))