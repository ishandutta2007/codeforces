mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    def gcd(a, b):
        if b == 0:
            return a
        while a % b:
            a, b = b, a%b
        return b

    def lcm(a, b):
        return (a * b) // gcd(a, b)

    N = int(input())
    A = list(map(int, input().split()))

    left = [0] * (N+1)
    right = [0] * (N+1)
    for i, a in enumerate(A):
        left[i+1] = gcd(left[i], a)
    for i in range(N-1, -1, -1):
        right[i] = gcd(right[i+1], A[i])

    ans = 0
    for i in range(N):
        #print(left[i], right[i+1], A[i])
        ans = gcd(ans, lcm(gcd(left[i], right[i+1]), A[i]))
        #print(ans)
    print(ans)


if __name__ == '__main__':
    main()