def main():
    import sys
    input = sys.stdin.readline

    N = int(input())
    B = list(map(int, input().split()))

    A = [0] * N
    X = [0] * N
    M = 0
    for i in range(N):
        X[i] = M
        A[i] = B[i] + X[i]
        M = max(M, A[i])
    print(*A)


if __name__ == '__main__':
    main()