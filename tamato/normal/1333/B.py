def main():
    import sys
    input = sys.stdin.buffer.readline

    ans = []
    for _ in range(int(input())):
        N = int(input())
        A = list(map(int, input().split()))
        B = list(map(int, input().split()))

        flg_pos = 0
        flg_neg = 0
        ok = 1
        for i in range(N):
            a = A[i]
            b = B[i]
            if a < b:
                if not flg_pos:
                    ok = 0
                    break
            elif a > b:
                if not flg_neg:
                    ok = 0
                    break
            if a == 1:
                flg_pos = 1
            elif a == -1:
                flg_neg = 1
        if ok:
            ans.append("YES")
        else:
            ans.append("NO")
    print(*ans, sep="\n")


if __name__ == '__main__':
    main()