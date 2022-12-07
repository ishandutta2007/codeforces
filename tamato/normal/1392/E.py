mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    def print_(L):
        print(*L)
        sys.stdout.flush()

    N = int(input())
    A = [[0] * N for _ in range(N)]
    for i in range(N):
        for j in range(N):
            A[i][j] = (i&1) * (1 << (i+j))
    for i in range(N):
        print_(A[i])

    Q = int(input())
    for q in range(Q):
        k = int(input())
        i = j = 0
        print_([i + 1, j + 1])
        for _ in range(2*N-2):
            flg = k >> (i+j+1) & 1
            if flg == 0:
                if i+1 < N:
                    if A[i+1][j] == 0:
                        i += 1
                    else:
                        j += 1
                else:
                    j += 1
            else:
                if i+1 < N:
                    if A[i+1][j] != 0:
                        i += 1
                    else:
                        j += 1
                else:
                    j += 1
            print_([i+1, j+1])


if __name__ == '__main__':
    main()