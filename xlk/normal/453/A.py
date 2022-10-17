m, n = map(int, raw_input().split())
print m - sum(map(lambda x: pow(float(x) / m, n), range(m)))