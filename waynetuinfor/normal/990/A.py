n, m, a, b = list(map(int, input().split()))
l = n // m
r = n // m if n % m == 0 else n // m + 1
l *= m
r *= m
print(min(a * (r - n), b * (n - l)))