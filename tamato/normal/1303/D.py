def main():
    import sys
    input = sys.stdin.readline

    t = int(input())
    for _ in range(t):
        N, M = map(int, input().split())
        A = list(map(int, input().split()))

        C = [0] * 100
        for a in A:
            C[a.bit_length() - 1] += 1

        ans = 0
        flg = 1
        for j in range(N.bit_length()):
            if N >> j & 1:
                if C[j]:
                    C[j] -= 1
                    C[j+1] += C[j] // 2
                else:
                    ok = 1
                    k = j + 1
                    while True:
                        if C[k]:
                            C[k] -= 1
                            ans += k - j
                            for l in range(k-1, j-1, -1):
                                C[l] += 1
                            break
                        k += 1
                        if k == 100:
                            ok = 0
                            break
                    if not ok:
                        flg = 0
                        break
            else:
                C[j+1] += C[j] // 2
        if flg:
            print(ans)
        else:
            print(-1)


if __name__ == '__main__':
    main()