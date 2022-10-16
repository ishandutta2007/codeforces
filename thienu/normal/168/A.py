n, x, y = map(int, input().split())
needed = (n * y + 99) // 100
print(max(0, needed - x))