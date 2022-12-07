mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.buffer.readline

    N = int(input())
    AC = []
    ans = 0
    for i in range(N):
        a, c = map(int, input().split())
        AC.append((a, c, i))
        ans += c
    AC.sort(key=lambda x: x[1])
    AC.sort(key=lambda x: x[0])

    b = AC[0][0] + AC[0][1]
    for i in range(1, N):
        a, c, j = AC[i]
        if a <= b:
            b = max(b, a + c)
        else:
            ans += a - b
            b = a + c
    print(ans)


if __name__ == '__main__':
    main()