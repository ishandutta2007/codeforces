def can(m,s):
    return s >= 0 and s <= 9*m

m,s = map(int,input().split())
if s == 0 and m == 1:
    print("0 0")
elif s == 0 or s > 9*m:
    print("-1 -1")
else:
    mins = ''
    maxs = ''
    x = s
    y = s
    for i in range(m):
        for j in range(10):
            if i == 0 and j == 0:
                continue
            if can(m-i-1,x-j):
                x -= j
                mins += str(j)
                break
        for j in range(9,-1,-1):
            if can(m-i-1,y-j):
                y -= j
                maxs += str(j)
                break   
    print(mins,maxs)