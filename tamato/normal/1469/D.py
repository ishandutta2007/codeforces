mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.buffer.readline

    def f(a, b):
        cnt = 0
        while a != 1:
            cnt += 1
            a, b = (b-1) // a + 1, a
            if a > b:
                a, b = b, a
        if b != 2:
            return 10**9
        else:
            return cnt

    for _ in range(int(input())):
        N = int(input())
        best_i = N-1
        best_cnt = 10**9
        for i in range(1, N):
            cnt = f(i, N)
            if cnt < best_cnt:
                best_cnt = cnt
                best_i = i
        ans = []
        for i in range(2, N):
            if i == best_i:
                continue
            ans.append((i, N))
        a = best_i
        b = N
        while a != 1:
            if a < b:
                ans.append((N, best_i))
                b = (b-1) // a + 1
            else:
                ans.append((best_i, N))
                a = (a-1) // b + 1

        assert len(ans) <= N+5
        print(len(ans))
        for x, y in ans:
            print(x, y)


if __name__ == '__main__':
    main()