mod = 1000000007
eps = 10**-9


def main():
    import sys
    from collections import Counter
    input = sys.stdin.buffer.readline

    for _ in range(int(input())):
        N = int(input())
        A = list(map(int, input().split()))

        C = Counter(A)
        q = 0
        for a in A:
            if C[a] & 1:
                q = -1
                break
        if q == -1:
            print(-1)
            continue

        B = []
        ans = []
        while True:
            if not A:
                break
            if A[-1] == A[-2]:
                A.pop()
                A.pop()
                B.append(2)
            else:
                a_last = A[-1]
                j = len(A) - 1
                for i in range(j - 1, -1, -1):
                    if A[i] == a_last:
                        ii = i
                        break
                A = A[:ii + 1] + A[ii + 1:][::-1]
                for k in range(ii + 1, j + 1):
                    ans.append((k, A[k]))
                B.append((j - ii) * 2)
        print(len(ans))
        for k, a in ans:
            print(k, a)
        print(len(B))
        B.reverse()
        print(*B)


if __name__ == '__main__':
    main()