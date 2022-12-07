mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.buffer.readline

    N, M = map(int, input().split())
    V = [0] * (N+1)
    ans = 0
    for _ in range(M):
        a, b = map(int, input().split())
        if a > b:
            a, b = b, a
        V[a] += 1
        if V[a] == 1:
            ans += 1
    Q = int(input())
    for _ in range(Q):
        q = list(map(int, input().split()))
        if q[0] == 3:
            print(N - ans)
        elif q[0] == 1:
            a, b = q[1:]
            if a > b:
                a, b = b, a
            V[a] += 1
            if V[a] == 1:
                ans += 1
        else:
            a, b = q[1:]
            if a > b:
                a, b = b, a
            V[a] -= 1
            if V[a] == 0:
                ans -= 1


if __name__ == '__main__':
    main()