from math import hypot
x1,y1,r1=map(float,raw_input().split())
x2,y2,r2=map(float,raw_input().split())
d=hypot(x1-x2,y1-y2)
if (d<abs(r1-r2)):
    d=abs(r1-r2)-d
else:    
    d=max(0,d-r1-r2)
print d/2