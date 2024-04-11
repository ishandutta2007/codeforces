import math
n,k=map(int,input().split())
things=[0]*(k+1)
for i in range(n):
    a=int(input())
    things[a]+=1
tot=0
for i in range(1,k+1):
    tot+=2*(things[i]//2)
tot+=math.ceil((n-tot)/2)
print(tot)