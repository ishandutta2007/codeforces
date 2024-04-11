n=input()
a=map(int,raw_input().split())
x=n-a[0]
print(['No','Yes'][[(a[i]+((-1)**i)*x+n)%n for i in range(n)]==range(n)])