mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    for _ in range(int(input())):
        S = input().rstrip('\n')
        N = len(S)

        l = 0
        cnt = [0, 0, 0]
        ans = N+1
        for r in range(N):
            s = S[r]
            if s == "1":
                cnt[0] += 1
            elif s == "2":
                cnt[1] += 1
            else:
                cnt[2] += 1
            if cnt[0] > 0 and cnt[1] > 0 and cnt[2] > 0:
                ans = min(ans, r - l + 1)
                while l < r:
                    ss = S[l]
                    if ss == "1":
                        cnt[0] += -1
                    elif ss == "2":
                        cnt[1] += -1
                    else:
                        cnt[2] += -1
                    l += 1
                    if cnt[0] == 0 or cnt[1] == 0 or cnt[2] == 0:
                        break
                    else:
                        ans = min(ans, r - l + 1)

        if ans == N+1:
            print(0)
        else:
            print(ans)


if __name__ == '__main__':
    main()