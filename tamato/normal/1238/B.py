def main():
    import sys
    input = sys.stdin.readline

    t = int(input())
    for _ in range(t):
        N, r = map(int, input().split())
        A = list(map(int, input().split()))
        A = list(set(A))
        A.sort()
        N = len(A)
        ans = 0
        y = 0
        for i in range(N-1, -1, -1):
            if A[i] <= y:
                break
            ans += 1
            y += r
        print(ans)


if __name__ == '__main__':
    main()