n=int(raw_input())
a=int(raw_input())
b=int(raw_input())
c=int(raw_input())

if n==1:
    print 0
elif n==2:
    print min(a,b)
else:
    print min ((n-1)*a,(n-1)*b,min(a,b)+(n-2)*c)
#a=[int(k) for k in raw_input().split(" ")]