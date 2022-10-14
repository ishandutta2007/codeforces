

q = int(raw_input())
 
while q > 0:
    q -= 1
    k, n, a, b = map(int, raw_input().split())
    l = k - n*b
    print(-1 if l <= 0 else min([n, (l - 1) / (a - b)]))