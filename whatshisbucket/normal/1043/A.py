import math
n=int(input())
a=list(map(int,input().split()))
sum=0
for i in range(n):
    sum+=a[i]
big=max(a)
biggish=math.ceil((2*sum+1)/n)
print(max(big,biggish))