n, m = map(int, input().split())
print(''.join(['4' for i in range(n)]))
print(''.join(['6' if i == n - 1 else '5' for i in range(n)]))