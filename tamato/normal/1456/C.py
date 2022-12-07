mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    N, K = map(int, input().split())
    A = list(map(int, input().split()))
    A.sort(reverse=True)
    if K == 0:
        ans = 0
        for i, a in enumerate(A):
            ans += a * (N-1 - i)
        print(ans)
        exit()

    cs = [0] * (N+1)
    ans = 0
    for i in range(N):
        cs[i+1] = cs[i] + A[i]
        ans += cs[i]
    cnt = 0
    ans_best = ans
    for i in range(N-1, -1, -1):
        if cnt % (K+1) == K:
            cnt += 1
        else:
            ans -= cs[i]
            ans += A[i] * (cnt // (K+1))
            ans -= A[i] * (cnt // (K+1))
            cnt += 1
        ans_best = max(ans_best, ans)
        #print(i, A[i], ans, ans_best, cnt, cs[i])
    print(ans_best)


if __name__ == '__main__':
    main()