n, k = list(map(int, input().split()))
a = list(map(int, input().split()))
i = k-1
if(a[i]==0):
    while((i>=0)and(a[i]<=0)):
        i-=1
elif((k<n)and(a[i]==a[i+1])):
    while((i+1<n)and(a[i]==a[i+1])):
        i+=1
print(i+1)