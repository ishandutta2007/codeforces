n,m=map(int,raw_input().split())
a=[raw_input() for i in range(n)]
x=sum(a[i].count('S')==0 for i in range(n))
print x*m+sum(sum(a[i][j]=='S' for i in range(n))==0 for j in range(m))*(n-x)