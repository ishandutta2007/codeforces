x,y,z=[int(k) for k in input().split(" ")]

bn=x//z+y//z
left=x+y-bn*z
if left>=z:
    print(bn+1,min(z-x%z,z-y%z))
else:
    print(bn,0)