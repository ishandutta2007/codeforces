__author__ = 'WildHamster'
n,k,p,x,y = map(int,input().split())
s = list(map(int,input().split()))
med = int(n - (int)(n+1)/2 + 1)
k1 = k
for i in s:
    if (i >= y):
        med -= 1
    x -= i
while (med > 0 and k < n):
    k += 1;
    s.append(y)
    x -= y
    med -= 1
while (k < n):
    s.append(1)
    x -= 1
    k += 1
if (x < 0 or med > 0):
    print(-1)
else:
    for i in range(k1,n):
        print(s[i])