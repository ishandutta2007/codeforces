mod = 1000000007
eps = 10**-9


def main():
    import sys
    from collections import Counter
    input = sys.stdin.readline
    N, p = map(int, input().split())
    A = list(map(int, input().split()))
    A.sort()

    """
    C = Counter(A)
    for a in A:
        if C[a] >= p:
            print(0)
            print("\n")
            exit()
    """
    x0 = -1
    for i in range(N):
        x0 = max(x0, A[i] - i)
    x1 = A[p-1]
    """
    if x0 >= x1:
        print(0)
        print("\n")
        exit()
    """

    dic = {}
    i = 0
    for x in range(x0, x0 + 2*10**5+1):
        while True:
            if i == N-1:
                break
            if A[i+1] <= x:
                i += 1
            else:
                break
        dic[x] = i+1

    ok = x0-1
    ng = x1
    mid = (ok+ng)//2
    while ng - ok > 1:
        x = mid
        flg = 1
        for i in range(N):
            if (dic[x+i] - i) % p == 0:
                flg = 0
                break
        if flg:
            ok = mid
        else:
            ng = mid
        mid = (ok+ng)//2
    print(ok - x0 + 1)
    X = list(range(x0, ok+1))
    print(*X)


if __name__ == '__main__':
    main()