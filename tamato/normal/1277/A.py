import sys
input = sys.stdin.readline

t = int(input())
num = []
for i in range(1, 10):
    for j in range(1, 10):
        num.append(int(str(i) * j))
for _ in range(t):
    N = int(input())
    ans = 0
    for n in num:
        if n <= N:
            ans += 1
    print(ans)