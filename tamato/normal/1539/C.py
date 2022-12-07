mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    N, K, X = map(int, input().split())
    A = list(map(int, input().split()))
    A.sort()
    C = []
    for i in range(N-1):
        if A[i+1] - A[i] > X:
            C.append((A[i+1] - A[i] - 1) // X)
    C.sort(reverse=True)
    while K:
        if not C:
            break
        if C[-1] <= K:
            K -= C[-1]
            C.pop()
        else:
            break
    print(len(C) + 1)


if __name__ == '__main__':
    main()