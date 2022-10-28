n=int(input())
s=list(map(int,input().split()))
counts=[None,0,0,0,0]
for i in range(n):
    counts[s[i]]+=1
taxis=counts[4]
sml=min(counts[1],counts[3])
counts[1]-=sml
counts[3]-=sml
taxis+=sml
taxis+=counts[3]
taxis+=counts[2]//2
counts[2]%=2
if counts[2]==1:
    taxis+=1
    counts[1]-=2
if counts[1]>0:
    taxis+=counts[1]//4
    counts[1]%=4
    if counts[1]>0:
        taxis+=1
print(taxis)