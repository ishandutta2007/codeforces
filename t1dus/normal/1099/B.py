from math import sqrt
n = int(input())
x = int(sqrt(n))
x = max(0,x-5)
ans = n+1
for i in range(x,x+11):
    for j in range(x,x+11):
        if i*j >= n:
            ans = min(ans,i+j)
print(ans)