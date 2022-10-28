b=int(input())
a=list(map(int,input().split()))
a.sort(reverse=True)
tot=0
for i in range(b//2):
    tot+=a[2*i]-a[2*i+1]
print(tot)