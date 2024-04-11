n = int(input())
for i in range(n):
    a, b = map(int, input().split())
    if b // 2 >= a:
        print(a, a*2)
    else:
        print(-1, -1)