def getC(n, k):
    r = 1
    for i in range(n, n - k, -1):
        r *= i
    for i in range(1, k + 1):
        r //= i
    return r

n = int(input())
print(getC(n, 5) + getC(n, 6) + getC(n, 7))