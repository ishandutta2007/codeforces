from math import ceil
n,m,k = map(int,input().split())
a = [0,0,0]
if (k%2):
    a[2] = 'L'
else:
    a[2] = 'R'
a[0] = ceil(k/(2*m))
k = ceil(k/2)
a[1] = ((k-1)%(m))+1
for i in a:
    print(i,end= ' ')
print("")