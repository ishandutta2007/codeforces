n=int(input())
a=list(map(int,input().split()))
for i in range(n):
    a[i]=abs(a[i])
a.sort()
a.append(1000000000000000)
low=0
high=0
tot=0
while low<n:
    if a[high]<=2*a[low]:
        high+=1
    else:
        tot+=high-low-1
        low+=1
print(tot)