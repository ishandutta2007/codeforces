import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    N = int(input())
    A = list(map(int, input().split()))
    ng = 1
    for i in range(N-1):
        if abs(A[i] - A[i+1]) > 1:
            print('YES')
            print(i+1, i+2)
            ng = 0
            break
    if ng:
        print('NO')