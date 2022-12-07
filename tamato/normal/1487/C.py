mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.buffer.readline

    for _ in range(int(input())):
        N = int(input())
        if N & 1:
            ans = []
            M = N // 2
            for i in range(N):
                for j in range(i+1, N):
                    if j - i <= M:
                        ans.append(1)
                    else:
                        ans.append(-1)
            print(*ans)
        else:
            ans = []
            M = N // 2
            for i in range(N):
                for j in range(i+1, N):
                    if j - i == M:
                        ans.append(0)
                    elif j - i < M:
                        ans.append(1)
                    else:
                        ans.append(-1)
            print(*ans)


if __name__ == '__main__':
    main()