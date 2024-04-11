t = int(input())

for _ in range(t):
    n = int(input())
    a = [int(i) for i in input().split()]
    a.sort()
    print('Yes' if n == 1 and a[0] == 1 or n > 1 and a[-1] - a[-2] <= 1 else 'No')