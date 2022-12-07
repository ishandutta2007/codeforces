mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    def ask(i, j):
        print("?", i+1, j+1)
        sys.stdout.flush()

    N = int(input())
    i_max = 0
    ans = [0] * N
    for i_new in range(1, N):
        ask(i_max, i_new)
        v0 = int(input())
        ask(i_new, i_max)
        v1 = int(input())
        if v0 > v1:
            ans[i_max] = v0
            i_max = i_new
        else:
            ans[i_new] = v1
    ans[i_max] = N
    ans.insert(0, "!")
    print(*ans)
    sys.stdout.flush()


if __name__ == '__main__':
    main()