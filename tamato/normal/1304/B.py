def main():
    import sys
    input = sys.stdin.readline

    N, M = map(int, input().split())
    has_rev = {}
    pal = []
    for _ in range(N):
        s = input().rstrip('\n')
        s_rev = s[::-1]
        if s == s_rev:
            pal.append(s)
        else:
            if s_rev in has_rev:
                has_rev[s_rev] = 1
            else:
                has_rev[s] = 0
    ans = []
    for s in has_rev:
        if has_rev[s]:
            ans.append(s)
    if ans:
        ans = ''.join(ans)
        ans_rev = ans[::-1]
    else:
        ans = ''
        ans_rev = ''
    if pal:
        ans = ans + pal[0] + ans_rev
        print(len(ans))
        print(ans)
    else:
        ans = ans + ans_rev
        print(len(ans))
        print(ans)






if __name__ == '__main__':
    main()