mod = 1000000007
eps = 10**-9
inf = 10**15


def main():
    import sys
    input = sys.stdin.buffer.readline

    def F(L, R, bad):
        NL = len(L)
        NR = len(R)
        ret = [inf] * NR
        L_sorted = [(l, i) for i, l in enumerate(L)]
        L_sorted.sort(key=lambda x: x[0])
        for i, r in enumerate(R):
            for l, k in L_sorted:
                if k * (NR+1) + i in bad:
                    continue
                else:
                    ret[i] = l + r
                    break
        return ret

    N1, N2, N3, N4 = map(int, input().split())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    C = list(map(int, input().split()))
    D = list(map(int, input().split()))

    M1 = int(input())
    if M1 == N1 * N2:
        print(-1)
        exit()
    bad1 = set()
    for _ in range(M1):
        x, y = map(int, input().split())
        x -= 1
        y -= 1
        bad1.add(x * (N2+1) + y)

    M2 = int(input())
    if M2 == N2 * N3:
        print(-1)
        exit()
    bad2 = set()
    for _ in range(M2):
        x, y = map(int, input().split())
        x -= 1
        y -= 1
        bad2.add(x * (N3 + 1) + y)

    M3 = int(input())
    if M3 == N3 * N4:
        print(-1)
        exit()
    bad3 = set()
    for _ in range(M3):
        x, y = map(int, input().split())
        x -= 1
        y -= 1
        bad3.add(y * (N3 + 1) + x)

    L = F(A, B, bad1)
    R = F(D, C, bad3)
    ans = min(F(L, R, bad2))
    if ans < inf:
        print(ans)
    else:
        print(-1)


if __name__ == '__main__':
    main()