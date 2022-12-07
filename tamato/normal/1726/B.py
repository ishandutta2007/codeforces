mod = 998244353


def main():
    import sys
    input = sys.stdin.readline

    for _ in range(int(input())):
        N, M = map(int, input().split())
        if M < N:
            print("No")
        else:
            if N & 1 == 0 and M & 1:
                print("No")
            elif N & 1 == 0:
                print("Yes")
                ans = [1] * (N - 2) + [(M - N + 2) // 2] * 2
                print(*ans)
            else:
                print("Yes")
                ans = [1] * (N - 1) + [M - (N - 1)]
                print(*ans)


if __name__ == '__main__':
    main()