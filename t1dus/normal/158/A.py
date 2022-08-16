coun = 0
n,k = map(int,input().split())
a = [int(j) for j in input().split()]
b = a[k-1]
for i in range(n):
    if a[i] >= b and a[i]>0:
        coun += 1
print(coun)