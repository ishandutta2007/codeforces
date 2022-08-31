a,b = map(int,input().split())
cur = 1
while a >= 0 and b >= 0:
    if a < cur:
        print("Vladik")
        break
    a -= cur
    cur += 1
    if b < cur:
        print("Valera")
        break
    b -= cur
    cur += 1