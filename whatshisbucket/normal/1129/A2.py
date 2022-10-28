n,m=map(int,input().split())
stations=[]
for i in range(n):
    stations.append([])
for i in range(m):
    a,b=map(int,input().split())
    stations[a-1].append((b-a)%n)
maxes=[]
for i in range(n):
    if len(stations[i])>0:
        big=min(stations[i])
    else:
        big=0
    maxes.append(n*max(len(stations[i])-1,0)+big)
out=[]
new=maxes[:]
big=0
for j in range(n):
    if new[j]+j>big and new[j]>0:
        big=new[j]+j
curr=big
out.append(str(curr))
for i in range(n-1):
    if maxes[i]>0:
        curr=max(curr-1,maxes[i]+n-1)
    else:
        curr=curr-1
    out.append(str(curr))
print(" ".join(out))