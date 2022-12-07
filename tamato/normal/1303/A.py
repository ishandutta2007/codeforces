def main():
    import sys
    input = sys.stdin.readline

    t = int(input())
    for _ in range(t):
        s = input().rstrip('\n')
        ans = 0
        c = s.count('1')
        cnt = 0
        for si in s:
            if 0 < cnt < c:
                if si == '0':
                    ans += 1
            if si == '1':
                cnt += 1
        print(ans)


if __name__ == '__main__':
    main()