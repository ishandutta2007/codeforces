def main():
    import sys
    input = sys.stdin.readline

    S = input().rstrip('\n')
    A = [int(s) for s in S]

    N = len(A)
    cnt = [[0] * 10 for _ in range(10)]
    for i in range(N-1):
        cnt[A[i]][A[i+1]] += 1
    ans = [[0] * 10 for _ in range(10)]
    for i in range(10):
        for j in range(10):
            if i <= j:
                for k in range(10):
                    for l in range(10):
                        if cnt[k][l]:
                            d = (l - k)%10
                            c = 100
                            for m in range(11):
                                for n in range(11):
                                    if m == n == 0:
                                        continue
                                    if (i*m + j*n)%10 == d:
                                        c = min(c, m+n)
                            if c == 100:
                                ans[i][j] = -1
                            else:
                                if ans[i][j] >= 0:
                                    ans[i][j] += (c-1) * cnt[k][l]
            else:
                ans[i][j] = ans[j][i]
    for i in range(10):
        print(*ans[i])


if __name__ == '__main__':
    main()