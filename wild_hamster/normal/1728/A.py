t = int(input())
for i in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    d = [-1, 0]
    for j in range(n):
        if a[j] > d[0]:
            d = [a[j], j]
    print(d[1] + 1)