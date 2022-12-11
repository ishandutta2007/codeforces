import math

def getC(n, k):
    return math.factorial(n) // math.factorial(k) // math.factorial(n - k)

n = int(input())
print(getC(n, 5) * math.factorial(n) // math.factorial(n - 5))