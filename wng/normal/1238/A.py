t=[int(k) for k in input().split(" ")][0]
for i in range(t):
    x,y=[int(k) for k in input().split(" ")]
    if x-y>1:
        print("YES")
    else:
        print("NO")