mod = 998244353


def main():
    import sys
    input = sys.stdin.readline

    N = int(input())
    B = list(map(int, input().split()))

    A = [[0] * N for _ in range(N)]

    if N == 2:
        if B == [0, 0]:
            A[0][1] = 1
        elif B == [0, 1]:
            A[1][1] = 1
        elif B == [1, 0]:
            A[0][0] = 1
        elif B == [1, 1]:
            A[0][0] = 1
            A[1][1] = 1
            A[0][1] = 1
        for h in range(N):
            print(*A[h])
        exit()

    for h in range(N):
        for w in range(N):
            A[h][(w + h) % N] = (w * h) % N

    for i, b in enumerate(B):
        if b & 1:
            bb = (b + N) // 2
        else:
            bb = b // 2
        for h in range(N):
            A[h][i] = (A[h][i] + bb) % N
        for w in range(N):
            A[i][w] = (A[i][w] + bb) % N
    for h in range(N):
        print(*A[h])


if __name__ == '__main__':
    main()