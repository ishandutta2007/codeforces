from math import pi

d,h,v,e = map(int,input().split())

r = d/2

low = 0
high = 10005

pos = -1

while low <= high:
    mid = (low+high)/2
    f = False
    volume = (pi)*(r)*(r)*(h+(mid*e))
    drink = mid*v
    if drink >= volume:
        pos = mid
        high = mid-0.0000001
    else:
        low = mid+0.0000001

if pos == -1:
    print("NO")
else:    
    print("YES")
    print(pos)