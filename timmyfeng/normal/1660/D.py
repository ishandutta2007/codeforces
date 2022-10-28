t = int(input())
 
for _ in range(t):
    n = int(input())
    a = [int(i) for i in input().split()]
    
    l, r = -1, 0
    answer, x, y = 1, n, 0
    while r <= n:
        while r < n and a[r] != 0:
            r += 1
        
        prod = 1
        for i in range(l + 1, r):
            prod *= a[i]
            if prod > answer:
                answer, x, y = prod, l + 1, n - i - 1
        
        prod = 1
        for i in range(r - 1, l, -1):
            prod *= a[i]
            if prod > answer:
                answer, x, y = prod, i, n - r
        
        l, r = r, r + 1
 
    print(x, y)