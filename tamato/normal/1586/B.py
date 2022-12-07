mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.buffer.readline

    for _ in range(int(input())):
        N, M = map(int, input().split())
        ABC = []
        for _ in range(M):
            a, b, c = map(int, input().split())
            ABC.append((a, b, c))
        ok = [1] * (N+1)
        for a, b, c in ABC:
            ok[b] = 0
        for v in range(1, N+1):
            if ok[v]:
                vv = v
                break
        for v in range(1, N+1):
            if v != vv:
                print(v, vv)


if __name__ == '__main__':
    main()