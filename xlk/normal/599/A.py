a, b, c = map(int, raw_input().split())
a = min(a, b + c)
b = min(b, a + c)
print a + b + min(c, a + b)