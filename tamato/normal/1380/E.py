mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    N, M = map(int, input().split())
    T = list(map(int, input().split()))

    ans = N-1
    S = [set() for _ in range(M+1)]
    for i, t in enumerate(T):
        S[t].add(i+1)

    for i in range(1, M+1):
        for x in S[i]:
            if x+1 in S[i]:
                ans -= 1
    print(ans)

    for _ in range(M-1):
        a, b = map(int, input().split())
        if len(S[a]) < len(S[b]):
            S[a], S[b] = S[b], S[a]
        for x in S[b]:
            if x-1 in S[a]:
                ans -= 1
            if x+1 in S[a]:
                ans -= 1
        for x in S[b]:
            S[a].add(x)
        print(ans)


if __name__ == '__main__':
    main()