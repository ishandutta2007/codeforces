import math

def divisorGenerator(n):
    large_divisors = []
    for i in range(1, int(math.sqrt(n) + 1)):
        if n % i == 0:
            yield i
            if i*i != n:
                large_divisors.append(n / i)
    for divisor in reversed(large_divisors):
        yield divisor


def solve(n):
    gcd = 0
    count = 0
    temp = n
    while True:
        count += 1
        temp = temp - count
        # print(temp)
        for i in range(count+1, temp):
            # print(i)
            if math.gcd(i, temp-i) == 1:
                # print("YES")
                gcd = i
                break
        if gcd != 0:
            break
    return [gcd, temp-gcd, n-gcd-temp+gcd]


# print(divisorGenerator(7))
# print(solve(7))

for _ in range(int(input())):
    n = int(input())
    print(*solve(n))