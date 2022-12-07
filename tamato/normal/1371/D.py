mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    for _ in range(int(input())):
        N, K = map(int, input().split())
        if K % N == 0:
            print(0)
        else:
            print(2)
        ans = [[0] * N for _ in range(N)]
        cnt = 0
        flg = 0
        for p in range(N):
            if flg:
                break
            for i in range(N):
                if cnt == K:
                    flg = 1
                    break
                ans[i][(i+p)%N] = 1
                cnt += 1
        for i in range(N):
            print("".join(map(str, ans[i])))


if __name__ == '__main__':
    main()