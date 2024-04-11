n = int(input())
print(-1 if n > 26 else n - len(set(input())))