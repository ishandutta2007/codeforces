mod = 1000000007
eps = 10**-9


def main():
    import sys
    from bisect import bisect_left
    input = sys.stdin.readline

    N, K = map(int, input().split())
    M = list(map(int, input().split()))
    C = list(map(int, input().split()))
    M.sort()
    C = [0] + C
    ans = []
    L = [-N-1]
    for _ in range(N):
        m = M.pop()
        c = C[m]
        i = bisect_left(L, -c+1)
        if i == len(L):
            L.append(-1)
            ans.append([m])
        else:
            L[i] -= 1
            ans[i-1].append(m)
    print(len(ans))
    for A in ans:
        print(len(A), *A)


if __name__ == '__main__':
    main()