x,y,z=[int(k) for k in input().split(" ")]
a,b,c=[int(k) for k in input().split(" ")]


if a>=x and a+b>=x+y and a+b+c>=x+y+z:
    print("YES")
else:
    print("NO")