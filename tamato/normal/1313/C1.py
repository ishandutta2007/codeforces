def main():
    import sys
    input = sys.stdin.readline

    N = int(input())
    A = list(map(int, input().split()))

    S = -1
    for mid in range(N):
        ans = [0] * N
        ans[mid] = A[mid]
        prev = A[mid]
        for j in range(mid-1, -1, -1):
            ans[j] = min(prev, A[j])
            prev = ans[j]
        prev = A[mid]
        for j in range(mid+1, N):
            ans[j] = min(prev, A[j])
            prev = ans[j]
        if sum(ans) > S:
            S = sum(ans)
            ans_best = ans
    print(*ans_best)


if __name__ == '__main__':
    main()