mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    N = int(input())
    A = list(map(int, input().split()))

    S = sum(A)
    if S == 1:
        print(-1)
        exit()
    div_list = [S]
    for d in range(2, int(S ** 0.5) + 1):
        if S % d == 0:
            div_list.append(d)
            div_list.append(S // d)
    if len(div_list) > 2:
        if div_list[-1] == div_list[-2]:
            div_list.pop()

    ans_best = 10**10
    for D in div_list:
        ans = 0
        cnt = 0
        i_list = []
        for i, a in enumerate(A):
            if a == 1:
                i_list.append(i)
                cnt += 1
                if cnt == D:
                    cnt = 0
                    j = i_list[D // 2]
                    for ii in i_list:
                        ans += abs(ii - j)
                    i_list = []
        ans_best = min(ans_best, ans)
    print(ans_best)


if __name__ == '__main__':
    main()