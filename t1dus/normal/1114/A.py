x,y,z = map(int,input().split())
a,b,c = map(int,input().split())
if a < x:
    print("NO")
    exit()
x -= a
y += x
if b < y:
    print("NO")
    exit()
y -= b
z += y
if c < z:
    print("NO")
    exit()
print("YES")