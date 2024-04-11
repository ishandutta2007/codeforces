n=int(input())
a=list(map(int,input().split()))
a.sort()
lose=False
pair=False
for i in range(n-1):
    if a[i]==a[i+1]==0:
        lose=True
    if a[i]==a[i+1]:
        if pair:
            lose=True
        pair=True
        if i>=1:
            if a[i]==a[i-1]+1:
                lose=True
if lose:
    print("cslnb")
else:
    eventual=n*(n-1)//2
    curr=sum(a)
    if (curr-eventual)%2==0:
        print("cslnb")
    else:
        print("sjfnb")