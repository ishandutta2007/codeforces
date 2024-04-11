t = int(input())
for _ in range(t):
    a, b = map(int, input().split())
    print(1 if a == 0 else a + 2 * b + 1)