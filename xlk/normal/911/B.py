n, a, b = map(int, raw_input().split())
print max(min(a / i, b / (n - i))for i in range(1, n))