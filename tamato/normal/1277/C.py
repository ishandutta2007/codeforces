import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    S = input()
    N = len(S)
    if N <= 2:
        print(0)
        continue
    ans = [0] * N
    for i in range(N-2):
        if S[i] == 'o' and S[i+1] == 'n' and S[i+2] == 'e':
            ans[i+1] = 1
        if S[i] == 't' and S[i+1] == 'w' and S[i+2] == 'o':
            ans[i+1] = 1
    for i in range(N-4):
        if S[i] == 't' and S[i+1] == 'w' and S[i+2] == 'o' and S[i+3] == 'n' and S[i+4] == 'e':
            ans[i+1] = 0
            ans[i+3] = 0
            ans[i+2] = 1
    print(sum(ans))
    a = []
    for i in range(N):
        if ans[i]:
            a.append(i+1)
    print(*a)