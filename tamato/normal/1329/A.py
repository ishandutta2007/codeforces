def main():
    import sys
    input = sys.stdin.readline

    N, M = map(int, input().split())
    L = list(map(int, input().split()))

    if sum(L) < N:
        print(-1)
        exit()

    ans = [0] * M
    left = N
    for i in range(M-1, -1, -1):
        if left - L[i] >= i:
            ans[i] = left - L[i] + 1
            left -= L[i]
        else:
            if i+L[i]-1 >= N:
                print(-1)
                exit()
            ans[i] = i+1
            left = i
    print(*ans)


if __name__ == '__main__':
    main()