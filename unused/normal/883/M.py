a, b = map(int, raw_input().split())
c, d = map(int, raw_input().split())

print max(1, abs(a - c)) * 2 + max(1, abs(b - d)) * 2 + 4