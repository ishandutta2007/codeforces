def main():
    import sys
    input = sys.stdin.readline

    t = int(input())
    for _ in range(t):
        N = int(input())
        A = list(map(int, input().split()))

        flg = 1
        for a in A:
            if a < 0:
                flg = 0
                break
        if flg:
            if A[0] > 0 and A[-1] > 0:
                print('YES')
            else:
                print('NO')
            continue

        cs = [0] * (N+1)
        for i in range(N):
            cs[i+1] = cs[i] + A[i]
        m = 10**9+7
        ans = -10**10
        for i in range(N-1):
            if cs[i] < m:
                m = cs[i]
            ans = max(ans, cs[i+1] - m)
        ans = max(ans, cs[-1] - min(cs[1:]))
        if sum(A) > ans:
            print('YES')
        else:
            print('NO')


if __name__ == '__main__':
    main()