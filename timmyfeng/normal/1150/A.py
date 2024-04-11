n, m, r = map(int, raw_input().split())
s = min(map(int, raw_input().split()))
b = max(map(int, raw_input().split()))

print(r + r / s * max(0, b - s))