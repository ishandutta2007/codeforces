def main():
    import sys
    input = sys.stdin.readline

    for _ in range(int(input())):
        S = input().rstrip('\n')
        N = len(S)
        ans = {S[0]: 0}
        i2s = {0: S[0]}
        ok = 1
        off = 0
        for i in range(N-1):
            s, ss = S[i], S[i+1]
            if ss not in ans:
                if (ans[s] + 1)%26 not in i2s:
                    ans[ss] = ans[s] + 1
                    i2s[(ans[s] + 1)%26] = ss
                elif (ans[s] - 1)%26 not in i2s:
                    ans[ss] = ans[s] - 1
                    i2s[(ans[s] - 1)%26] = ss
                    off += 1
                else:
                    ok = 0
                    break
            else:
                if abs(ans[ss] - ans[s]) > 1:
                    ok = 0
                    break
                if ans[s] == 26-off and ans[ss] == ans[s] - 1:
                    ok = 0
                    break
                if ans[s] == 26-off-1 and ans[ss] == ans[s] + 1:
                    ok = 0
                    break
        if ok:
            print('YES')
            ret = [''] * 26
            not_used = []
            for s in 'qwertyuiopasdfghjklzxcvbnm':
                if s in ans:
                    ret[ans[s] + off] = s
                else:
                    not_used.append(s)
            i = 0
            for s in not_used:
                while ret[i] != '':
                    i += 1
                ret[i] = s
            print(''.join(ret))
        else:
            print('NO')


if __name__ == '__main__':
    main()