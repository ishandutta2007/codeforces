x,y,z,a,b,c=map(int,input().split())
stairs=abs(x-y)*a
elevator=(abs(z-x)+abs(x-y))*b+3*c
if stairs<elevator:
    print("NO")
else:
    print("YES")