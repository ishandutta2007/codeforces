N = int(input())
S_raw = input()

S = [0] * N
for i in range(N):
    if S_raw[i] == 'B':
        S[i] = 1

S_ori = S[:]
ans = []
for i in range(N-1):
    if S[i] == 1:
        S[i] = 0
        S[i+1] = 1 - abs(S[i+1])
        ans.append(i+1)
if S[-1] == 0:
    print(len(ans))
    print(*ans)
    exit()

S = S_ori[:]
ans = []
for i in range(N-1):
    if S[i] == 0:
        S[i] = 1
        S[i+1] = 1 - abs(S[i+1])
        ans.append(i+1)
if S[-1] == 1:
    print(len(ans))
    print(*ans)
else:
    print(-1)