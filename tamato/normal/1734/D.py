mod = 998244353
inf = 10 ** 17


def main():
    import sys
    input = sys.stdin.readline

    for _ in range(int(input())):
        N, K = map(int, input().split())
        A = [inf] + list(map(int, input().split())) + [inf]

        st_r = []
        cur = 0
        mi = 0
        for i in range(K+1, N+2):
            cur += A[i]
            mi = min(mi, cur)
            if cur >= 0:
                st_r.append((mi, cur))
                cur = 0
                mi = 0
        st_r.reverse()

        st_l = []
        cur = 0
        mi = 0
        for i in range(K - 1, -1, -1):
            cur += A[i]
            mi = min(mi, cur)
            if cur >= 0:
                st_l.append((mi, cur))
                cur = mi = 0
        st_l.reverse()

        x = A[K]
        ans = "YES"
        while st_l and st_r:
            ok = 0
            if x + st_l[-1][0] >= 0:
                y, z = st_l.pop()
                x += z
                ok = 1
            if x + st_r[-1][0] >= 0:
                y, z = st_r.pop()
                x += z
                ok = 1
            if not ok:
                ans = "NO"
                break
        print(ans)


if __name__ == '__main__':
    main()