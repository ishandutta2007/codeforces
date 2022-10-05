def solution(n, a):
    a = sorted(a)
    s = set(a)
    
    count = 0
    
    for i in range(n):
        for j in range(i+1, n):
            x, y = a[i], a[j]
            if x < y:
                x, y = y, x
            if x % y in s:
                continue
            count += 1
            print(x, y)
            if count == n // 2:
                return
    
    

t = int(input())
for i in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    solution(n, a)