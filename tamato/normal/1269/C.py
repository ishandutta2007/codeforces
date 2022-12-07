N, K = map(int, input().split())
A = input()

B = [A[i%K] for i in range(N)]
A_int = int(A)
B_int = int(''.join(B))
if B_int >= A_int:
    print(N)
    print(''.join(B))
else:
    Ak = str(int(A[:K]) + 1)
    B = [Ak[i%K] for i in range(N)]
    print(N)
    print(''.join(B))