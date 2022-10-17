a = map(int, raw_input().split())
a = sorted(a)
print ['NO', 'YES'][a[0] == 1 or a[:2] == [2, 2] or a == [3, 3, 3] or a == [2, 4, 4]]