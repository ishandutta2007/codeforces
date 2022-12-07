mod = 1000000007
eps = 10**-9


def main():
    import sys
    from random import sample
    input = sys.stdin.readline

    def ask(L, R):
        print("?", len(L), len(R))
        print(*L)
        print(*R)
        sys.stdout.flush()
        f = int(input())
        return f


    for _ in range(int(input())):
        N = int(input())
        ans = [0] * (N+1)
        L = []
        for i in range(1, N):
            L.append(i)
            f = ask(L, [i+1])
            if f:
                ii = i+1
                ans[ii] = 1
                break
        for i in range(ii+1, N+1):
            f = ask([ii], [i])
            if f:
                ans[i] = 1
        ok = ii-1
        ng = 0
        mid = (ok+ng) // 2
        while ok - ng > 1:
            f = ask(list(range(1, mid+1)), [ii])
            if f:
                ok = mid
            else:
                ng = mid
            mid = (ok+ng)//2
        ans[ok] = 1
        A = []
        for i in range(1, N+1):
            if ans[i] == 0:
                A.append(i)
        A = ["!", len(A)] + A
        print(*A)
        sys.stdout.flush()
    exit()


if __name__ == '__main__':
    main()