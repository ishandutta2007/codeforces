n = input()
a = sorted(map(int, raw_input().split()))
b = [a[i] - a[i - 1] for i in range(1, n)]
print min(b), b.count(min(b))