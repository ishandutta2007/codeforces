n=int(input())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
goods=[]
for t1 in range(4):
    for t2 in range(4):
        if t1|t2==a[0] and t1&t2==b[0]:
            goods.append([t1,t2])
for i in range(n-2):
    pairs=[]
    for t1 in range(4):
        for t2 in range(4):
            if t1|t2==a[i+1] and t1&t2==b[i+1]:
                pairs.append([t1,t2])
    for guy in goods:
        if guy[-1]>=0:
            kill=True
            c=guy[-1]
            for dude in pairs:
                if dude[0]==c:
                    kill=False
                    guy.append(dude[1])
            if kill:
                guy.append(-1)
win=False
for i in range(len(goods)):
    if goods[i][-1]>=0:
        win=True
        print("YES")
        winstr=""
        for guy in goods[i]:
            winstr+=str(guy)+" "
        print(winstr[:-1])
        break
if not win:
    print("NO")