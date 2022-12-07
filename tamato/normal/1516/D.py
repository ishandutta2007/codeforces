mod = 1000000007
eps = 10**-9


def main():
    import sys
    from math import gcd
    input = sys.stdin.buffer.readline

    V = 10**5
    minfactor = list(range(V+1))
    for d in range(2, V+1):
        for x in range(2, V+1):
            if d*x > V:
                break
            if minfactor[d*x] == d*x:
                minfactor[d*x] = d

    N, Q = map(int, input().split())
    A = [0] + list(map(int, input().split())) + [1]
    N += 1

    M = 1
    seen = [0] * (V+1)
    r = 1
    nxt_0 = [-1] * (N+1)
    for l in range(1, N+1):
        while True:
            if r == N:
                break
            a = A[r]
            d_set = set()
            while a != 1:
                d = minfactor[a]
                d_set.add(d)
                a //= d
            ok = 1
            for d in d_set:
                if seen[d]:
                    ok = 0
                    break
            if not ok:
                break
            else:
                r += 1
                for d in d_set:
                    seen[d] = 1
        nxt_0[l] = r
        a = A[l]
        while a != 1:
            d = minfactor[a]
            seen[d] = 0
            a //= d
    nxt = [[-1] * (N+1) for _ in range(18)]
    nxt[0] = nxt_0
    for lv in range(1, 18):
        for l in range(1, N+1):
            nxt[lv][l] = nxt[lv-1][nxt[lv-1][l]]

    for _ in range(Q):
        l, r = map(int, input().split())
        ans = 0
        for lv in range(17, -1, -1):
            l_new = nxt[lv][l]
            if l_new <= r:
                ans += 1 << lv
                l = l_new
        ans += 1
        print(ans)


if __name__ == '__main__':
    main()