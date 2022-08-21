import os,sys
n=int(raw_input())
m=int(raw_input())
a=map(int,raw_input().split(' '))
b=map(int,raw_input().split(' '))
t=0
for i in range(0,n)[::-1]:
    x=b[(i+1)%n]
    if x==1:
        print '-1'
        sys.exit(0)
    t=(t*1.0*x+m)/(x-1)
    x=a[i]
    if x==1:
        print '-1'
        sys.exit(0)
    t=(t*1.0*x+m)/(x-1)
print '%.10lf'%t