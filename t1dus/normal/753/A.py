n = int(input())
x = n
i = 1
while n >= i:
    n -= i
    i += 1
print(i-1)
for j in range(1,i):
    if j == i-1:
        print(x)
        break
    else:
        print(j,end= ' ')
        x -= j