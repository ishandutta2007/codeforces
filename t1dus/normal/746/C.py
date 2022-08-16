s,x1,x2 = map(int,input().split())
t1,t2 = map(int,input().split())
p,d = map(int,input().split())
ans = abs(x2-x1)*t2
xyz = abs(x2-x1)*t1
if x2 > x1:
    if d == 1:
        if p > x1:
            xyz += ((s-p)+(s)+(x1))*t1
        else:
            xyz += (x1-p)*t1
    else:
        xyz += (p+x1)*t1
else:
    if d == 1:
        xyz += ((s-p)+(s-x1))*t1
    else:
        if p >= x1:
            xyz += (p-x1)*t1
        else:
            xyz += ((p)+(s)+(s-x1))*t1
print(min(ans,xyz))