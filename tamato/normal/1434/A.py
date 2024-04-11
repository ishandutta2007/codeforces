mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    A = list(map(int, input().split()))
    N = int(input())
    B = list(map(int, input().split()))
    A.sort()
    B.sort()
    cnt = {i: 0 for i in range(N)}
    C = []
    for i in range(N):
        for j in range(6):
            C.append((B[i] - A[j], i))
    C.sort(key=lambda x: x[0])

    r = -1
    zero_num = N
    ans = 10**10
    for l in range(6*N):
        if l > 0:
            cnt[C[l-1][1]] -= 1
            if cnt[C[l-1][1]] == 0:
                zero_num += 1
        while zero_num != 0:
            r += 1
            if r == 6*N:
                print(ans)
                exit()
            _, i = C[r]
            cnt[i] += 1
            if cnt[i] == 1:
                zero_num -= 1
        ans = min(ans, C[r][0] - C[l][0])
    print(ans)


if __name__ == '__main__':
    main()