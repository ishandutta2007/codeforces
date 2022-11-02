w,m=map(int,raw_input().split())
a=[w**i for i in range(101)]*2
m+=sum(a)/2
for i in sorted(a)[::-1]:m-=i*(m>=i)
print ["NO","YES"][m==0]