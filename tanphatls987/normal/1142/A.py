import math

n, k = map(int, input().split())
a, b = map(int, input().split())


x = n * k + 1
y = -1

st = [a, k - a] 

for L in st : 
    for i in range(n) : 
        en = [i * k + b, (i + 1) * k - b]
        for R in en :
            dist = R - L
            if (dist < 0) :
                dist = dist + n * k
            com = math.gcd(dist, n * k)
            cyc = (n * k) // com
            x = min(x, cyc)
            y = max(y, cyc)
print(x, y)