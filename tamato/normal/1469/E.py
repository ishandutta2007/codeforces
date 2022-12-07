mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    for _ in range(int(input())):
        N, K = map(int, input().split())
        S = input().rstrip('\n')

        if K <= 20:
            T = [int(s) ^ 1 for s in S]
            bad = set()
            t = 0
            for i in range(K):
                t += T[i] * (1 << (K - i - 1))
            beki = 1 << (K-1)
            for i in range(N-K+1):
                bad.add(t)
                if i != N-K:
                    t -= T[i] * beki
                    t *= 2
                    t += T[i+K]
            ok = 0
            for i in range(1 << K):
                if i not in bad:
                    print("YES")
                    print(bin(i)[2:].zfill(K))
                    ok = 1
                    break
            if not ok:
                print("NO")
        else:
            print("YES")
            T = [int(s) ^ 1 for s in S]
            bad = set()
            zero_left = [0] * N
            for i, t in enumerate(T[:-1]):
                if t == 0:
                    zero_left[i+1] = zero_left[i] + 1
            t = 0
            beki = 1 << 19
            for i in range(N-K+1):
                if zero_left[i + K-20] == K - 20:
                    t = 0
                    for j in range(20):
                        t += T[i + K-20 + j] * (1 << (20 - j - 1))
                    bad.add(t)
                elif zero_left[i + K-20] > K - 20:
                    t -= T[i + K-20 - 1] * beki
                    t *= 2
                    t += T[i + K - 1]
                    bad.add(t)
            for i in range(1 << K):
                if i not in bad:
                    print(bin(i)[2:].zfill(K))
                    break


if __name__ == '__main__':
    main()