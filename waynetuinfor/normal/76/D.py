a = int(input())
b = int(input())
if (a - b) % 2 == 1:
    print("-1")
    exit(0)
x = (a - b) // 2
y = a - x
print(x, y)