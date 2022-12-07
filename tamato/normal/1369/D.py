mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.buffer.readline

    N = 2*10**6
    a = 1
    b = 0
    C = [0, 0]
    for lv in range(2, N+1):
        C.append((b*4)%mod)
        a, b = (a + 2*b)%mod, a
    ans = [0] * (N+1)
    for lv in range(1, N+1):
        ans[lv] = (ans[lv-3] + C[lv])%mod
    for _ in range(int(input())):
        print(ans[int(input())])


if __name__ == '__main__':
    main()