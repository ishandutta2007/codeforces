t = int(input())
for _ in range(t):
    s = input()
    N = len(s)
    ans = [s[i] for i in range(N)]
    flg = 0
    for i in range(N):
        if ans[i] == '?':
            used = []
            if i > 0:
                used.append(ans[i-1])
            if i+1 < N:
                used.append(ans[i+1])
            if 'a' not in used:
                ans[i] = 'a'
            elif 'b' not in used:
                ans[i] = 'b'
            else:
                ans[i] = 'c'
        else:
            if i > 0:
                if ans[i-1] == ans[i]:
                    print(-1)
                    flg = 1
                    break
            if i+1 < N:
                if ans[i+1] == ans[i]:
                    print(-1)
                    flg = 1
                    break
    if not flg:
        print(''.join(ans))