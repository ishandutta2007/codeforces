# AC
mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.buffer.readline

    for _ in range(int(input())):
        M = int(input())
        LR_raw = []
        val = set()
        for _ in range(M):
            l, r = map(int, input().split())
            LR_raw.append((l, r))
            val.add(l)
            val.add(r)
        val = sorted(list(val))
        val2idx = {x: i for i, x in enumerate(val)}
        LR = []
        N = len(val)
        segment = [set() for _ in range(N)]
        for l_, r_ in LR_raw:
            l = val2idx[l_]
            r = val2idx[r_]
            LR.append((l, r))
            segment[l].add(r)

        dp = [[0] * N for _ in range(N)]
        for d in range(1, N+1):
            for l in range(N):
                r = l + d - 1
                if r < N:
                    if l+1 <= r:
                        dp[l][r] = dp[l+1][r]
                    for rr in segment[l]:
                        if rr >= r:
                            continue
                        dp[l][r] = max(dp[l][r], dp[l][rr] + dp[rr+1][r])
                    if r in segment[l]:
                        dp[l][r] += 1
        print(dp[0][-1])


if __name__ == '__main__':
    main()