n = int(input())
x = 0
for i in range(n+1):
    if i*(i+1)//2 <= n:
        x = i
print(x)
for i in range(x-1):
    print(i+1, end = " ")
print(n-x*(x-1)//2)