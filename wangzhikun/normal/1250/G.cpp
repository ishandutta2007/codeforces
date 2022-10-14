from collections import Counter
T = int(input())
for _ in range(T):
    N,K,D = map(int,input().split())
    A = list(map(int,input().split()))
    ctr = Counter(A[:D])
    ans = len(ctr)
    for i in range(N-D):
        ctr[A[D+i]] += 1
        ctr[A[i]] -= 1
        if not ctr[A[i]]:
            del ctr[A[i]]
        ans = min(ans, len(ctr))
    print(ans)