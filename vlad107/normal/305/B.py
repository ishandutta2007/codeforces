p,q=map(long,raw_input().split())
n=int(input())
a=map(long,raw_input().split())
x,y=a[n-1],1
for i in range(n-1)[::-1]:x,y=a[i]*x+y,x
print ['NO','YES'][p*y==q*x]