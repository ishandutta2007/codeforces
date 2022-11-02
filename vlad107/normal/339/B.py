R=lambda:map(int,raw_input().split())
n,m=R()
a=[1]+R()
print sum(a[i]-a[i-1] if a[i]>=a[i-1] else a[i]-a[i-1]+n for i in range(1,m+1))