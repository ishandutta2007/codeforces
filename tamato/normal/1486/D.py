mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline
    from collections import deque

    # A: list, k: window size
    def slide_min(A, k):
        D = deque()
        ret = []
        for i in range(k):
            a = A[i]
            while True:
                if D:
                    if a <= A[D[-1]]:
                        D.pop()
                    else:
                        D.append(i)
                        break
                else:
                    D.append(i)
                    break
        ret.append(A[D[0]])
        for i in range(1, len(A) - k + 1):
            if D[0] == i - 1:
                D.popleft()
            j = i + k - 1
            a = A[j]
            while True:
                if D:
                    if a <= A[D[-1]]:
                        D.pop()
                    else:
                        D.append(j)
                        break
                else:
                    D.append(j)
                    break
            ret.append(A[D[0]])
        return ret

    N, K = map(int, input().split())
    A = list(map(int, input().split()))

    ok = min(A)
    ng = max(A) + 1
    mid = (ok+ng) // 2
    while ng - ok > 1:
        AA = [0]
        for a in A:
            if a >= mid:
                AA.append(AA[-1] - 1)
            else:
                AA.append(AA[-1] + 1)
        AA.extend([N+3] * (N - K + 3))
        S = slide_min(AA, N - K + 1)
        mi = N+3
        for i in range(N - K + 1):
            mi = min(mi, S[i + K] - AA[i])
        if mi <= -1:
            ok = mid
        else:
            ng = mid
        mid = (ok + ng) // 2
    print(ok)


if __name__ == '__main__':
    main()