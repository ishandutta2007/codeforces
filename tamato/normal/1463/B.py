mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    for _ in range(int(input())):
        N = int(input())
        A = list(map(int, input().split()))

        S0 = S1 = 0
        for i, a in enumerate(A):
            if i&1:
                S1 += a
            else:
                S0 += a
        if S0 < S1:
            B = []
            for i, a in enumerate(A):
                if i&1:
                    B.append(a)
                else:
                    B.append(1)
        else:
            B = []
            for i, a in enumerate(A):
                if i & 1:
                    B.append(1)
                else:
                    B.append(a)
        print(*B)


if __name__ == '__main__':
    main()