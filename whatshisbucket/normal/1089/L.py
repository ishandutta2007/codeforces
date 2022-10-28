n,k=map(int,input().split())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
chose=[]
for i in range(k):
    chose.append([])
for i in range(n):
    chose[a[i]-1].append(b[i])
for i in range(k):
    chose[i].sort()
notdone=0
useful=[]
for i in range(k):
    l=len(chose[i])
    if l==0:
        notdone+=1
    else:
        useful+=chose[i][:-1]
useful.sort()
print(sum(useful[:notdone]))