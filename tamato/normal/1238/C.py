def main():
    import sys
    input = sys.stdin.readline

    t = int(input())
    for _ in range(t):
        h, N = map(int, input().split())
        A = list(map(int, input().split()))

        ans = 0
        i = 0
        while True:
            if i == N-1:
                break
            if A[i] - A[i+1] > 1:
                A[i] = A[i+1] + 1
            else:
                if i == N-2:
                    if A[i] == 2:
                        break
                    else:
                        ans += 1
                        break
                if A[i+2] == A[i+1] - 1:
                    i += 2
                else:
                    ans += 1
                    i += 1
        print(ans)


if __name__ == '__main__':
    main()