mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.buffer.readline

    for _ in range(int(input())):
        N = int(input())
        A = list(map(int, input().split()))

        AI = [(a, i) for i, a in enumerate(A)]
        AI.sort(key=lambda x: abs(x[0]), reverse=True)
        B = []
        cur = 0
        for a, i in AI[:-1]:
            if cur * a > 0:
                cur -= a
                B.append(-1)
            else:
                cur += a
                B.append(1)
        a = AI[-1][0]
        if cur == 0:
            B[0] = 2
            cur += AI[0][0]
        BB = []
        for b in B:
            BB.append(b * a)
        BB.append(-cur)
        ans = [0] * N
        for j in range(N):
            a, i = AI[j]
            ans[i] = BB[j]
        print(*ans)
        S = 0
        T = 0
        for i, b in enumerate(ans):
            S += abs(b)
            T += A[i] * b
            assert b != 0
        assert S <= 10 ** 9
        assert T == 0


if __name__ == '__main__':
    main()