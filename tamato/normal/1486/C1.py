mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    def ask(l, r):
        if l == r:
            print("!", l)
            sys.stdout.flush()
            exit()
        print("?", l, r)
        sys.stdout.flush()
        p = int(input())
        return p

    N = int(input())
    L = 0
    R = N+1
    pos_2nd_max = ask(1, N)
    while R - L > 3:
        mid = (L + R) // 2
        if pos_2nd_max <= mid:
            p = ask(L+1, mid)
            if p == pos_2nd_max:
                R = mid + 1
            else:
                L = mid
                pos_2nd_max = ask(mid+1, R-1)
        else:
            p = ask(mid, R-1)
            if p == pos_2nd_max:
                L = mid-1
            else:
                R = mid
                pos_2nd_max = ask(L+1, mid-1)
    if R - L == 2:
        print("!", L+1)
        sys.stdout.flush()
    elif R - L == 3:
        p = L+1 + L+2 - ask(L+1, R-1)
        print("!", p)
        sys.stdout.flush()


if __name__ == '__main__':
    main()