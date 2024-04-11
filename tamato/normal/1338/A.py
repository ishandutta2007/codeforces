mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    for _ in range(int(input())):
        N = int(input())
        A = list(map(int, input().split()))

        ans = 0
        m = A[0]
        for i in range(1, N):
            if A[i] < m:
                ans = max(ans, (m-A[i]).bit_length())
            m = max(A[i], m)
        print(ans)


if __name__ == '__main__':
    main()