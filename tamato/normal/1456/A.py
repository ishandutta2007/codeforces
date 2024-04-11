mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    for _ in range(int(input())):
        N, p, k = map(int, input().split())
        p -= 1
        S = input().rstrip('\n')
        x, y = map(int, input().split())

        cost = [0] * N
        for i in range(p, N):
            if S[i] == "0":
                cost[p + (i - p)%k] += x
                if i + k < N:
                    cost[i + k] -= x
        for i in range(p+1, N):
            if i - k >= p:
                cost[i] += cost[i-k]
        ans = float("inf")
        for i in range(p, N):
            ans = min(ans, cost[i] + y * (i - p))
        print(ans)


if __name__ == '__main__':
    main()