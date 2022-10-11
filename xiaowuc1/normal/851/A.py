n, k, t = (int(x) for x in raw_input().split())
rhs = min(n, t)
lhs = max(1, t-k+1)
print rhs-lhs+1