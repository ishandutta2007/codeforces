def main():
    import sys
    input = sys.stdin.readline

    q = int(input())
    for _ in range(q):
        a, b = map(int, input().split())
        S = input().rstrip('\n')
        S += '!'

        win = 1
        cnt = 0
        flg = 0
        num = 0
        for s in S:
            if s == '.':
                cnt += 1
            else:
                if cnt:
                    if b <= cnt < a:
                        win = 0
                        break
                    elif cnt < b:
                        pass
                    elif cnt < 2*b:
                        num += 1
                    else:
                        num += 1
                        if flg:
                            flg = 2
                            win = 0
                            break
                        else:
                            flg = 1
                            tmp = cnt
                cnt = 0
        if flg == 1:
            if num % 2 == 0:
                if a >= 2*b:
                    win = 0
                else:
                    if not 2*a <= tmp <= a+3*b-2:
                        win = 0
            else:
                if tmp <= a+2*b-2:
                    pass
                elif 3*a <= tmp <= a+4*b-2:
                    pass
                else:
                    win = 0
        elif flg == 0:
            if num % 2 == 0:
                win = 0

        if win:
            print('Yes')
        else:
            print('No')


if __name__ == '__main__':
    main()