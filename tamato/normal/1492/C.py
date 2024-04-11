mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    N, M = map(int, input().split())
    S = input().rstrip('\n')
    T = input().rstrip('\n')

    L = [0] * M
    cnt = 0
    for i, s in enumerate(S):
        if s == T[cnt]:
            L[cnt] = i
            cnt += 1
            if cnt == M:
                break
    R = [0] * M
    cnt = M-1
    for i in range(N-1, -1, -1):
        s = S[i]
        if s == T[cnt]:
            R[cnt] = i
            cnt -= 1
            if cnt == -1:
                break

    ans = 1
    for i in range(M-1):
        ans = max(ans, R[i+1] - L[i])
    print(ans)


if __name__ == '__main__':
    main()