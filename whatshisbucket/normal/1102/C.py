import math
n,x,y=map(int,input().split())
a=list(map(int,input().split()))
if x>y:
    print(n)
else:
    count=0
    for guy in a:
        if guy<=x:
            count+=1
    print(math.ceil(count/2))