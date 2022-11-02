t = int(input())

for i in range(t):
    a, b = map(int, input().split(" "))
    if a % b == 0:
        print(0)
    else:
        print(b - a % b)