def calc(n):
    res = 1
    while n > 0:
        res *= n % 10
        n /= 10
    return res

n = input()

base = 1
ans = calc(n)
while base < n:
    while n / base % 10 != 9:
        n -= base
    ans = max(ans, calc(n))
    base *= 10

print(ans)