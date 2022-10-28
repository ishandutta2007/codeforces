n=int(input())
pos=[]
diffs=[]
for i in range(n):
    a,b=map(int,input().split())
    pos.append((a,b))
for i in range(n):
    c,d=map(int,input().split())
    diffs.append((c,d))
pos.sort()
diffs.sort(reverse=True)
print(pos[0][0]+diffs[0][0],pos[0][1]+diffs[0][1])