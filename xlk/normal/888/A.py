input()
z = map(int, raw_input().split())
print sum(i > j < k or i < j > k for i, j, k in zip(z, z[1:], z[2:]))