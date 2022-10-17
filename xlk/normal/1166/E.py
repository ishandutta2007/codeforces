m,n=map(int,input().split())
l=[set(map(int,input().split()[1:]))for i in range(m)]
print(['','im'][any(not(i&j)for i in l for j in l)]+'possible')