x,y,z=map(int,input().split())
maxi=x//z+y//z
x%=z
y%=z
if x>y:
    x,y=y,x
if x+y<z:
    print(maxi,0)
else:
    print(maxi+1,z-y)