def main():
    import sys
    from collections import defaultdict
    input = sys.stdin.readline

    X = int(input())
    X_raw = X

    if X == 1:
        print(1, 1)
        exit()

    x = int(X ** 0.5)
    if x**2 > X:
        x -= 1
    if (x+1)**2 <= X:
        x += 1
    prime = defaultdict(int)
    for d in range(2, x+1):
        while X % d == 0:
            prime[d] += 1
            X //= d
    if X != 1:
        prime[X] += 1

    if len(prime) == 1:
        print(1, X_raw)
        exit()

    ans = []
    for d in prime.keys():
        ans.append(d ** prime[d])
    M = len(ans)
    dp = [[0] * (x+1) for _ in range(M+1)]
    dp[0][1] = 1
    for i in range(M):
        for j in range(x+1):
            if dp[i][j]:
                if j * ans[i] <= x:
                    dp[i+1][j*ans[i]] = 1
                dp[i+1][j] = 1
    for a in range(x, -1, -1):
        if dp[-1][a]:
            print(a, X_raw//a)
            break


if __name__ == '__main__':
    main()