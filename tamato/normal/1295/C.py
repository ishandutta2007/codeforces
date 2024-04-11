def main():
    import sys
    input = sys.stdin.readline

    for _ in range(int(input())):
        S = input().rstrip('\n')
        T = input().rstrip('\n')
        N = len(S)

        nxt = [[N+1] * 26 for _ in range(N+1)]
        for i in range(N, 0, -1):
            s = S[i-1]
            for j in range(26):
                c = chr(j+97)
                if c == s:
                    nxt[i-1][j] = i
                else:
                    nxt[i-1][j] = nxt[i][j]
        seen = {}
        for s in S:
            seen[s] = 1

        ans = 1
        i = 0
        for t in T:
            t_ = ord(t) - 97
            if t not in seen:
                ans = -1
                break
            i = nxt[i][t_]
            if i == N+1:
                ans += 1
                i = nxt[0][t_]
            #print(t, i)
        print(ans)


if __name__ == '__main__':
    main()