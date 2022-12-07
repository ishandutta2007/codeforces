mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    div = [0] * (10**7+1)
    for d in range(2, 10**7+1):
        if div[d]:
            continue
        for j in range(1, 10**7+1):
            if d*j > 10**7:
                break
            if div[d*j] == 0:
                div[d*j] = d

    N = int(input())
    A = list(map(int, input().split()))

    ans1 = [-1] * N
    ans2 = [-1] * N
    for i, a in enumerate(A):
        p = div[a]
        v1 = 1
        while a % p == 0:
            v1 *= p
            a //= p
        if a != 1:
            ans1[i] = v1
            ans2[i] = a
    print(*ans1)
    print(*ans2)


if __name__ == '__main__':
    main()