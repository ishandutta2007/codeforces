mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.buffer.readline

    N, Q = map(int, input().split())
    A = list(map(int, input().split()))
    cnt = [A.count(0), A.count(1)]
    for _ in range(Q):
        t, x = map(int, input().split())
        if t == 1:
            a = A[x-1]
            cnt[a] -= 1
            cnt[a^1] += 1
            A[x-1] ^= 1
        else:
            if x <= cnt[1]:
                print(1)
            else:
                print(0)


if __name__ == '__main__':
    main()