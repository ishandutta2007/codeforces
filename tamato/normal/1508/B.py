mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.buffer.readline

    for _ in range(int(input())):
        N, K = map(int, input().split())

        if N == 1:
            if K == 1:
                print(1)
            else:
                print(-1)
            continue

        cnt = 1
        ok = 0
        for _ in range(N-1):
            cnt *= 2
            if cnt >= K:
                ok = 1
                break
        if not ok:
            print(-1)
            continue

        K -= 1
        skip = [0] * (N+1)
        for i in range(N-1):
            if K >> i & 1:
                skip[N-1-i] = 1

        ans = []
        st = []
        for i in range(1, N+1):
            if skip[i]:
                st.append(i)
            else:
                ans.append(i)
                while st:
                    ans.append(st.pop())
        print(*ans)


if __name__ == '__main__':
    main()