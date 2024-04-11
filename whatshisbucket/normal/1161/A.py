n,k=map(int,input().split())
x=list(map(int,input().split()))
first=[k]*n
last=[-1]*n
for i in range(k):
    last[x[i]-1]=i
for i in range(k):
    first[x[-i-1]-1]=k-i-1
tot=0
for i in range(n-1):
    if first[i+1]>last[i]:
        tot+=1
    if first[i]>last[i+1]:
        tot+=1
for i in range(n):
    if first[i]==k and last[i]==-1:
        tot+=1
print(tot)