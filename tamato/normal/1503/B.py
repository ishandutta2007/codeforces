mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    N = int(input())
    cur_1 = []
    cur_2 = []
    for i in range(N):
        for j in range(N):
            if (i+j) & 1:
                cur_1.append(i * N + j)
            else:
                cur_2.append(i * N + j)
    cnt_1 = cnt_2 = 0
    flg = 0
    for _ in range(N * N):
        a = int(input())
        if flg == 0:
            if a != 1:
                print(1, cur_1[cnt_1] // N + 1, cur_1[cnt_1] % N + 1)
                sys.stdout.flush()
                cnt_1 += 1
                if cnt_1 == (N * N) // 2:
                    flg = 1
            else:
                print(2, cur_2[cnt_2] // N + 1, cur_2[cnt_2] % N + 1)
                sys.stdout.flush()
                cnt_2 += 1
                if cnt_2 == (N * N + 1) // 2:
                    flg = 2
        elif flg == 1:
            if a == 2:
                b = 3
            else:
                b = 2
            print(b, cur_2[cnt_2] // N + 1, cur_2[cnt_2] % N + 1)
            sys.stdout.flush()
            cnt_2 += 1
        else:
            if a == 1:
                b = 3
            else:
                b = 1
            print(b, cur_1[cnt_1] // N + 1, cur_1[cnt_1] % N + 1)
            sys.stdout.flush()
            cnt_1 += 1


if __name__ == '__main__':
    main()