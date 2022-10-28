t=int(input())
for i in range(t):
    d=int(input())
    if d==0:
        print("Y",0,0)
    elif 0<d<4:
        print("N")
    else:
        print("Y",(d+(d**2-4*d)**0.5)/2,(d-(d**2-4*d)**0.5)/2)