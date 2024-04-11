n, m, k = map(int, raw_input().split())
print [pow(2, (n - 1) * (m - 1), 10 ** 9 + 7), 0][k + (n + m) % 2 == 0]