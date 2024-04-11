mod = 1000000007
eps = 10**-9


def main():
    import sys
    from collections import Counter
    input = sys.stdin.readline

    N = int(input())
    A = list(map(int, input().split()))

    C = Counter(A)
    T = []
    for v in C:
        if C[v] >= 2:
            T.append(v)
    if len(T) >= 2:
        v0, v1 = T[0], T[1]
        print("YES")
        ans = [-1] * 4
        for i, a in enumerate(A):
            if a == v0:
                if ans[0] == -1:
                    ans[0] = i+1
                else:
                    ans[2] = i+1
            elif a == v1:
                if ans[1] == -1:
                    ans[1] = i+1
                else:
                    ans[3] = i+1
        print(*ans)
        exit()
    elif len(T) == 1:
        v = T[0]
        if C[v] >= 4:
            ans = []
            for i, a in enumerate(A):
                if a == v:
                    ans.append(i+1)
                    if len(ans) == 4:
                        break
            print("YES")
            print(*ans)
            exit()

    D = [None] * 5000001
    for i in range(N):
        ai = A[i]
        for j in range(i+1, N):
            aj = A[j]
            if D[ai+aj] is None:
                D[ai+aj] = [(i+1, j+1)]
            else:
                for k, l in D[ai+aj]:
                    ijkl = set([i+1, j+1, k, l])
                    if len(ijkl) == 4:
                        print("YES")
                        print(i+1, j+1, k, l)
                        exit()
                D[ai+aj].append((i+1, j+1))
    print("NO")


if __name__ == '__main__':
    main()