mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    def ask(l, r):
        print("?", l, r)
        sys.stdout.flush()
        p = int(input())
        return p

    N = int(input())
    L = 0
    R = N+1
    pos_2nd_max = ask(1, N)
    flg = -1
    if pos_2nd_max == 1:
        flg = 1
    else:
        p = ask(1, pos_2nd_max)
        if p == pos_2nd_max:
            flg = 0
        else:
            flg = 1

    if flg == 0:
        ok = 1
        ng = pos_2nd_max
        mid = (ok+ng) // 2
        while ng - ok > 1:
            p = ask(mid, pos_2nd_max)
            if p == pos_2nd_max:
                ok = mid
            else:
                ng = mid
            mid = (ok + ng) // 2
        print("!", ok)
    else:
        ok = N
        ng = pos_2nd_max
        mid = (ok + ng) // 2
        while ok - ng > 1:
            p = ask(pos_2nd_max, mid)
            if p == pos_2nd_max:
                ok = mid
            else:
                ng = mid
            mid = (ok + ng) // 2
        print("!", ok)


if __name__ == '__main__':
    main()