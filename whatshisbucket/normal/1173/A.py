x,y,z=map(int,input().split())
if z>=abs(x-y) and z>0:
    print("?")
elif x-y>0:
    print("+")
elif x-y<0:
    print("-")
else:
    print(0)