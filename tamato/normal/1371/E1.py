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
    for x in range(x0, x0 + 10**5+1):
        while True:
            if i == N-1:
                break
            if A[i+1] <= x:
                i += 1
            else:
                break
        dic[x] = i+1

    ans = []
    for x in range(x0, x1):
        flg = 1
        for i in range(N):
            if (dic[x+i] - i) % p == 0:
                flg = 0
                break
        if flg:
            ans.append(x)
    print(len(ans))
    print(*ans)


if __name__ == '__main__':
    main()