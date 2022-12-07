def main():
    import sys
    input = sys.stdin.buffer.readline

    mod = 998244353

    N = int(input())
    A = []
    for _ in range(N):
        A.append(list(map(int, input().split())))

    prob = [0] * (10**6 + 3)
    want = [0] * (10**6 + 3)
    invN = pow(N, mod-2, mod)
    for i in range(N):
        k = A[i][0]
        invK = pow(k, mod-2, mod)
        for j in range(1, k+1):
            prob[A[i][j]] = (prob[A[i][j]] + (invN * invK)%mod) % mod
            want[A[i][j]] += 1

    ans = 0
    for i in range(1, 10**6+1):
        ans = (ans + ((prob[i] * want[i])%mod * invN)%mod)%mod
    print(ans)


if __name__ == '__main__':
    main()