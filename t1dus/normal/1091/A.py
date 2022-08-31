y,b,r = map(int,input().split())
if b > y+1:
    b = y+1
else:
    y = b-1
if r > b+1:
    r = b+1
else:
    b = r-1
    y = b-1
print(y+b+r)