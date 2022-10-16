n, m = map(int, input().split())
l = []
while n > 0:
    l.append(n % m)
    n = n // m
# print(l)
print("YES" if len(l) == len(set(l)) else "NO")