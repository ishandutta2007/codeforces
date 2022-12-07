t = int(input())
for _ in range(t):
    r, g, b = map(int, input().split())
    M = max(r, g, b)
    if M > (r+g+b) - M + 1:
        print('No')
    else:
        print('Yes')