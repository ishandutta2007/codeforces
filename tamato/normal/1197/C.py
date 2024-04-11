mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    N, K = map(int, input().split())
    A = list(map(int, input().split()))
    B = [A[i+1] - A[i] for i in range(N-1)]
    B.sort()
    ans = A[-1] - A[0]
    for _ in range(K-1):
        ans -= B.pop()
    print(ans)


if __name__ == '__main__':
    main()