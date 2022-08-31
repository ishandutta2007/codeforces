n,k = map(int,input().split())
a = [int(i) for i in input().split()]
coun = 0
for j in range(1,n):
    if a[j] >= k-a[j-1]:
        continue
    x = k-a[j-1]
    coun += x-a[j]
    a[j] = x
print(coun)
for y in a:
    print(y,end=' ')
print("")