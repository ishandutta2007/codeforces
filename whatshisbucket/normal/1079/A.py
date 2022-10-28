import math
n,k=map(int,input().split())
utensils=[0]*100
a=list(map(int,input().split()))
for i in range(n):
    utensils[a[i]-1]+=1
b=max(utensils)
mini=k*math.ceil(b/k)
stolen=0
for guy in utensils:
    if guy>0:
        stolen+=mini-guy
print(stolen)