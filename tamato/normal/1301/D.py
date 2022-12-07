def main():
    import sys
    input = sys.stdin.readline

    N, M, K = map(int, input().split())

    if 4*N*M - 2*N - 2*M < K:
        print('NO')
        exit()
    print('YES')

    def finish(ans):
        print(len(ans))
        for a, b in ans:
            print(a, b)
        exit()

    ans = []
    ans_append = ans.append

    if N == 1:
        if M - 1 >= K:
            ans_append((K, 'R'))
            finish(ans)
        else:
            ans_append((M-1, 'R'))
            ans_append((K - M + 1, 'L'))
            finish(ans)

    if N-1 >= K:
        ans_append((K, 'D'))
        finish(ans)
    else:
        ans_append((N-1, 'D'))
        K -= N-1

    if N-1 >= K:
        ans_append((K, 'U'))
        finish(ans)
    else:
        ans_append((N-1, 'U'))
        K -= N-1

    for w in range(M-1):
        ans_append((1, 'R'))
        K -= 1
        if K == 0:
            finish(ans)

        if 3 * (N-1) < K:
            ans_append((N-1, 'DLR'))
            K -= 3*(N-1)
        else:
            j = K // 3
            if j:
                ans_append((j, 'DLR'))
                K -= j*3
            if K == 0:
                finish(ans)
            elif K == 1:
                ans_append((1, 'D'))
                finish(ans)
            elif K == 2:
                ans_append((1, 'DL'))
                finish(ans)

        if N - 1 >= K:
            ans_append((K, 'U'))
            finish(ans)
        else:
            ans_append((N - 1, 'U'))
            K -= N - 1

    ans_append((K, 'L'))
    finish(ans)


if __name__ == '__main__':
    main()