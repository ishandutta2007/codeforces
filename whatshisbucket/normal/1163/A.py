n,m=map(int,input().split())
if m==0:
    m=1
print(min(n-m,m))