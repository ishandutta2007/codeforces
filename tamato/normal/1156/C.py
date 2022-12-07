mod = 1000000007
eps = 10**-9


def main():
    import sys
    from bisect import bisect_left
    input = sys.stdin.readline

    N, z = map(int, input().split())
    A = list(map(int, input().split()))
    A.sort()

    B = A[:N//2]
    C = A[(N+1)//2:]
    cnt = [0] * (N//2)
    for i in range(1, N//2+1):
        b = B[-i]
        j = bisect_left(C, b+z)
        if j != N//2:
            cnt[j] += 1
    ans = 0
    room = 0
    for j in range(1, N//2+1):
        if cnt[-j]:
            ans += 1
            cnt[-j] -= 1
            if room:
                k = min(room, cnt[-j])
                ans += k
                room -= k
        else:
            room += 1
    print(ans)


if __name__ == '__main__':
    main()