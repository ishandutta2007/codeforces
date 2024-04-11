q=int(input())
for i in range(q):
    l,r,d=map(int,input().split())
    if d<l:
        print(d)
    else:
        print(d*(int(r/d)+1))