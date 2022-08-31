w,h = map(int,input().split())
w1,h1 = map(int,input().split())
w2,h2 = map(int,input().split())
for i in range(h,-1,-1):
    w += i
    if i == h1:
        w = max(0,w-w1)
    if i == h2:
        w = max(0,w-w2)
print(w)