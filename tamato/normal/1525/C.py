mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    def solve(info, ans, M):
        st = []
        N = len(info)
        for i in range(N):
            x, j, d = info[i]
            if d == "L":
                if st:
                    x0, j0 = st.pop()
                    ans[j] = ans[j0] = abs(x - x0) // 2
                else:
                    st.append((-x, j))
            else:
                st.append((x, j))
        while len(st) > 1:
            x1, j1 = st.pop()
            x1 = M + (M - x1)
            x0, j0 = st.pop()
            ans[j0] = ans[j1] = abs(x1 - x0) // 2

    for _ in range(int(input())):
        N, M = map(int, input().split())
        X = list(map(int, input().split()))
        LR = list(input().split())

        even = []
        odd = []
        for i, x in enumerate(X):
            if x & 1:
                odd.append((x, i, LR[i]))
            else:
                even.append((x, i, LR[i]))
        odd.sort(key=lambda y: y[0])
        even.sort(key=lambda y: y[0])
        ans = [-1] * N
        solve(odd, ans, M)
        solve(even, ans, M)
        print(*ans)


if __name__ == '__main__':
    main()