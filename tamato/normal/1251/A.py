def main():
    import sys
    input = sys.stdin.readline

    t = int(input())
    for _ in range(t):
        S = input().rstrip('\n')
        N = len(S)
        ans = {}
        i = 0
        while True:
            if i == N-1:
                ans[S[i]] = 1
                break
            if S[i] == S[i+1]:
                i += 2
                if i == N:
                    break
            else:
                ans[S[i]] = 1
                i += 1
        ret = []
        for s in ans.keys():
            ret.append(s)
        ret.sort()
        print(''.join(ret))


if __name__ == '__main__':
    main()