mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.buffer.readline

    for _ in range(int(input())):
        N, K = map(int, input().split())
        A = list(map(int, input().split()))
        A.sort(reverse=True)
        if K == 0:
            print(A[0] - A[-1])
        else:
            print(sum(A[:min(K + 1, len(A))]))


if __name__ == '__main__':
    main()