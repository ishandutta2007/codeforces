mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    for _ in range(int(input())):
        N = int(input())
        A = list(map(int, input().split()))

        flg = 1
        for i in range(31, -1, -1):
            cnt = 0
            for a in A:
                if a >> i & 1:
                    cnt += 1
            if cnt & 1:
                flg = 0
                if cnt % 4 == 1:
                    print("WIN")
                else:
                    if N & 1:
                        print("LOSE")
                    else:
                        print("WIN")
                break
        if flg:
            print("DRAW")


if __name__ == '__main__':
    main()