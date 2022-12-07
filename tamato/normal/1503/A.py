mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    for _ in range(int(input())):
        N = int(input())
        S = input().rstrip('\n')

        A = []
        B = []
        cnt_A = 0
        cnt_B = 0
        num_1 = S.count("1")
        if num_1 & 1:
            print("NO")
            continue
        cnt_1 = 0
        flg = 0
        for i, s in enumerate(S):
            if s == "1":
                if cnt_1 < num_1 // 2:
                    A.append("(")
                    B.append("(")
                    cnt_A += 1
                    cnt_B += 1
                else:
                    A.append(")")
                    B.append(")")
                    cnt_A -= 1
                    cnt_B -= 1
                cnt_1 += 1
            else:
                if flg:
                    A.append(")")
                    cnt_A -= 1
                    B.append("(")
                    cnt_B += 1
                else:
                    A.append("(")
                    cnt_A += 1
                    B.append(")")
                    cnt_B -= 1
                flg ^= 1
            if cnt_A < 0 or cnt_B < 0:
                break
        if cnt_A == cnt_B == 0:
            print("YES")
            print("".join(A))
            print("".join(B))
        else:
            print("NO")


if __name__ == '__main__':
    main()