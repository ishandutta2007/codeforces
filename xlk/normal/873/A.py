n, k, x = map(int, raw_input().split())
print sum(map(int, raw_input().split()[:-k])) + k * x