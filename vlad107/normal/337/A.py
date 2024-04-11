R=lambda:map(int,raw_input().split())
n,m=R()
a=sorted(R())
print min(a[i-1]-a[i-n] for i in range(n,m+1))