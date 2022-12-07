mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.buffer.readline

    N = int(input())
    XY = []
    for _ in range(N):
        XY.append(tuple(map(int, input().split())))

    ans1 = ans2 = 0
    for i in range(N):
        cnt = [0] * 4
        xi, yi = XY[i]
        for j in range(N):
            if j == i:
                continue
            xj, yj = XY[j]
            if (xi - xj)%4 == 0 and (yi - yj)%4 == 0:
                cnt[0] += 1
            elif (xi - xj)%4 == 2 and (yi - yj)%4 == 0:
                cnt[1] += 1
            elif (xi - xj)%4 == 0 and (yi - yj)%4 == 2:
                cnt[2] += 1
            else:
                cnt[3] += 1
        ans1 += cnt[0] * (cnt[0] - 1) // 2
        ans2 += cnt[1] * (cnt[1] - 1) // 2
        ans2 += cnt[2] * (cnt[2] - 1) // 2
        ans2 += cnt[3] * (cnt[3] - 1) // 2
    assert ans1 % 3 == 0
    print(ans1 // 3 + ans2)


if __name__ == '__main__':
    main()