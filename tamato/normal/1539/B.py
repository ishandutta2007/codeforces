mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    N, Q = map(int, input().split())
    S = input().rstrip('\n')

    A = []
    for s in S:
        A.append(ord(s) - 96)
    cs = [0] * (N+1)
    for i, a in enumerate(A):
        cs[i+1] = cs[i] + a
    for _ in range(Q):
        l, r = map(int, input().split())
        print(cs[r] - cs[l-1])


if __name__ == '__main__':
    main()