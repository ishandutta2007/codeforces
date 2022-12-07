q = int(input())
for _ in range(q):
    a, b, n, S = map(int, input().split())
    if n*a + b < S:
        print('NO')
        continue
    if S % n <= b:
        print('YES')
    else:
        print('NO')