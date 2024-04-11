mod = 1000000007
eps = 10**-9


def main():
    import sys
    from math import gcd
    input = sys.stdin.readline

    # ax + by == gcd(a, b) x, y
    # gcd(a, b) > 0
    def extgcd(a, b):
        if a == b:
            return 1, 0
        if a == b == 0:
            return 0, 0
        if b == 0:
            return 1, 0
        AB = [a, b]
        while b:
            a, b = b, a % b
            AB.append(b)
        if len(AB) == 3:
            return 0, 1
        k = AB[-2]
        x = 1
        y = -(AB[-4] // AB[-3])
        for i in range(len(AB) - 4, 0, -1):
            a, b = AB[i - 1], AB[i]
            x, y = y, x - y * (a // b)
        if k < 0:
            x, y = -x, -y
        return x, y

    N, M, K = map(int, input().split())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))

    a2i = [-1] * 1000001
    b2i = [-1] * 1000001
    for i, a in enumerate(A):
        a2i[a] = i
    for i, b in enumerate(B):
        b2i[b] = i

    g = gcd(N, M)
    first_same = [-1] * N
    L = N * M // g
    for i, a in enumerate(A):
        j = b2i[a]
        if j == -1:
            continue
        if i%g != j%g:
            continue
        x, y = extgcd(N, -M)
        x *= (j-i) // g
        # y *= (j-i) // g
        first_same[i] = N * x + i
        first_same[i] %= L

    FS = set()
    for i in range(N):
        if first_same[i] != -1:
            FS.add(first_same[i])

    # 1 cycle
    cycle_num = L - len(FS)

    ans = (K // cycle_num) * L
    K %= cycle_num

    if K == 0:
        for v in range(L-1, -1, -1):
            if v in FS:
                ans -= 1
            else:
                break
        print(ans)
        exit()

    ok = L-1
    ng = -1
    mid = (ok + ng) // 2
    FS = list(FS)
    while ok - ng > 1:
        cnt = mid + 1
        for f in FS:
            if f <= mid:
                cnt -= 1
        if cnt >= K:
            ok = mid
        else:
            ng = mid
        mid = (ok + ng) // 2
    ans += ok + 1
    print(ans)


if __name__ == '__main__':
    main()