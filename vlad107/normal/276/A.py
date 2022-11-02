R=lambda:map(int,raw_input().split())
n,k=R()
print max(x[0]-max(0,x[1]-k)for x in [R() for _ in range(n)])