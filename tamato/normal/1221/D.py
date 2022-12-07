def main():
    import sys
    input = sys.stdin.readline

    q = int(input())
    for _ in range(q):
        N = int(input())
        A = [-100]
        B = [0]
        for _ in range(N):
            a, b = map(int, input().split())
            A.append(a)
            B.append(b)

        inf = 10**20
        dp = [[inf] * (3) for _ in range(N+1)]
        dp[0][0] = 0
        for i in range(N):
            for add in range(3):
                for add_next in range(3):
                    if A[i] + add != A[i+1] + add_next:
                        dp[i+1][add_next] = min(dp[i+1][add_next], dp[i][add] + B[i+1] * add_next)
        print(min(dp[-1]))


if __name__ == '__main__':
    main()