n = int(input())
a = list(map(int, input().split()))
x = [0 for i in range(5)]
for i in range(n):
    x[a[i]] += 1
total = x[4]
x[4] = 0
total += x[3]
x[1] = max(0,x[1]-x[3])
x[3] = 0
total += (x[2]-1)//2+1
if(x[2]%2==1):
    x[1] = max(0, x[1]-2)
x[2] = 0
total += (x[1]-1)//4+1
print(total)