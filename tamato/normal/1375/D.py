mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.buffer.readline

    def MEX(A):
        N = len(A)
        cnt = [0] * (N+1)
        for a in A:
            cnt[a] += 1
        for i in range(N+1):
            if cnt[i] == 0:
                return i

    for _ in range(int(input())):
        N = int(input())
        A = list(map(int, input().split()))

        fixed = 0
        for i, a in enumerate(A):
            if i == a:
                fixed += 1

        ans = []
        while True:
            if fixed == N:
                break
            m = MEX(A)
            if m < N:
                A[m] = m
                ans.append(m+1)
                fixed += 1
            else:
                for i, a in enumerate(A):
                    if i != a:
                        A[i] = N
                        ans.append(i+1)
                        break
        assert len(ans) <= 2*N
        print(len(ans))
        print(*ans)


if __name__ == '__main__':
    main()