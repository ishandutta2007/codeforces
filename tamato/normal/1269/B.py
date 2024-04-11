N, M = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
B.sort()

B0 = B[0]
ans = M
for i in range(N):
    p = (B0 - A[i]) % M
    A_new = [(Aj + p) % M for Aj in A]
    A_new.sort()
    if A_new == B:
        ans = min(ans, p)

print(ans)