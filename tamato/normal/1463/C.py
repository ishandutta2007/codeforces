mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.buffer.readline

    for t in range(int(input())):
        N = int(input())
        T = []
        X = []
        for _ in range(N):
            t, x = map(int, input().split())
            T.append(t)
            X.append(x)
        v = 1 if X[0] > 0 else -1
        x_cur = 0
        ans = 0
        x_dest = X[0]

        if N == 1:
            print(1)
            continue

        for i in range(1, N):
            t, x = T[i], X[i]
            dt = t - T[i-1]
            x_new = x_cur + v * dt
            if v > 0:
                x_new = min(x_new, x_dest)
                if x_cur <= X[i-1] <= x_new:
                    ans += 1
                    #print(t, i)
                x_cur = x_new
                if x_new == x_dest:
                    x_dest = x
                    v = 1 if x_dest > x_cur else -1
            else:
                x_new = max(x_new, x_dest)
                if x_cur >= X[i - 1] >= x_new:
                    ans += 1
                    #print(t, i)
                x_cur = x_new
                if x_new == x_dest:
                    x_dest = x
                    v = 1 if x_dest > x_cur else -1

        t, x = T[-1], X[-1]
        if v > 0:
            if x_cur <= x <= x_dest:
                ans += 1
        else:
            if x_cur >= x >= x_dest:
                ans += 1

        print(ans)


if __name__ == '__main__':
    main()