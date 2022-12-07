mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    for _ in range(int(input())):
        N, a, b = map(int, input().split())
        if a == 1:
            if (N-1) % b == 0:
                print("Yes")
            else:
                print("No")
        else:
            ok = 0
            for k in range(40):
                if a ** k > N:
                    break
                M = N - a ** k
                if M % b == 0:
                    ok = 1
                    break
            if ok:
                print("Yes")
            else:
                print("No")


if __name__ == '__main__':
    main()