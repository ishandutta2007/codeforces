n = input()
a = map(int, raw_input().split())
x = min(a)
b = [i for i in range(n)if a[i] == x]
print min(b[i] - b[i - 1]for i in range(1, len(b)))