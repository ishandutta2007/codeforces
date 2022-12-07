mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    flg = 0

    def ask2(A):
        N = len(A)
        S = [a + p for a, p in zip(A, P)]
        for i in range(N):
            for j in range(i+1, N):
                if S[i] == S[j]:
                    return i+1
        return 0

    def ask(A):
        print("?", " ".join(map(str, A)))
        sys.stdout.flush()
        k = int(input())
        return k

    N = int(input())
    if flg:
        P = list(map(int, input().split()))
    ans = [0] * N
    for i in range(1, N):
        A = [i] * N
        A[-1] = N
        k = ask(A)
        if k != 0:
            ans[-1] = i
            break
    if ans[-1] == 0:
        ans[-1] = N
    y = ans[-1]
    for x in range(1, N+1):
        if x == y:
            continue
        A = [y] * N
        A[-1] = x
        k = ask(A)
        ans[k-1] = x
    print("!", " ".join(map(str, ans)))
    sys.stdout.flush()


if __name__ == '__main__':
    main()