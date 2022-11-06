t = int(input())
for i in range(t):
    a = int(input())
    a = 180 - a
    if 360 % a == 0: print("YES")
    else: print("NO")