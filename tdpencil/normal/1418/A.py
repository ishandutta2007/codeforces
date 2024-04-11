for i in range(int(input())):
    x, y, k = map(int, input().split())
    print(((y + 1) * k - 1 + x - 2) // (x - 1) + k)