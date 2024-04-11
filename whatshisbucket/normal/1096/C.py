import math
t=int(input())
for i in range(t):
    a=int(input())
    b=math.gcd(180,a)
    if b+a==180:
        print(2*180//b)
    else:
        print(180//b)