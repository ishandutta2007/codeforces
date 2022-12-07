mod = 1000000007
eps = 10**-9


def main():
    import sys
    from bisect import bisect_left
    input = sys.stdin.buffer.readline

    def len_LIS(seg):
        n = len(seg)
        l = seg[0]
        r = seg[-1]
        A = seg[1:-1]
        LIS = [l]
        for a in A:
            if not l <= a <= r:
                continue
            j = bisect_left(LIS, a+1)
            if j == len(LIS):
                LIS.append(a)
            else:
                LIS[j] = a
        return len(LIS) - 1

    N, K = map(int, input().split())
    A = [-10**10] + list(map(int, input().split())) + [10**10]
    for i in range(N+2):
        A[i] -= i
    if K:
        B = [0] + list(map(int, input().split())) + [N+1]
    else:
        B = [0, N+1]

    ans = 0
    for i in range(K+1):
        l = B[i]
        r = B[i+1]
        if A[r] - A[l] < 0:
            print(-1)
            exit()
        ans += r - l - 1 - len_LIS(A[l: r+1])
    print(ans)


if __name__ == '__main__':
    main()