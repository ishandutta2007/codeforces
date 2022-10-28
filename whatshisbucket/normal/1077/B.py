n=int(input())
a=list(map(int,input().split()))
disturbed=[]
for i in range(n-2):
    if a[i]==a[i+2]==1 and a[i+1]==0:
        disturbed.append(i+1)
tot=0
a=0
while a<len(disturbed):
    tot+=1
    if a==len(disturbed)-1:
        a+=1
    elif disturbed[a+1]-disturbed[a]==2:
        a+=2
    else:
        a+=1
print(tot)