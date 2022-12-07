mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    N = int(input())
    P = list(map(int, input().split()))

    L = [0] * N
    R = [0] * N
    for i in range(1, N):
        if P[i] > P[i-1]:
            L[i] = L[i-1] + 1
    for i in range(N-2, -1, -1):
        if P[i] > P[i+1]:
            R[i] = R[i+1] + 1
    ma_L = max(L)
    ma_R = max(R)
    ma = max(ma_L, ma_R)
    flg = 0
    for i in range(N):
        if L[i] == R[i] == ma:
            flg += 1
        elif L[i] == ma or R[i] == ma:
            flg = 2
    if ma & 1:
        flg = 2
    if flg == 1:
        print(1)
    else:
        print(0)


if __name__ == '__main__':
    main()