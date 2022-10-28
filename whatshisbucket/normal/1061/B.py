n,k=map(int,input().split())
a=list(map(int,input().split()))
a.sort(reverse=True)
worst=0
maxi=a[0]
a.append(0)
for i in range(n+1):
    bad=maxi-a[i]-i
    worst=max(worst,bad)
print(sum(a)-n-worst)