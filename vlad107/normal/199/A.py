n=int(input())
if (n==0):
    print 0,0,0
    exit(0)
a,b=0,1
while 1:
    if (a+b==n):
        print 0,a,b
        break
    b,a=a+b,b