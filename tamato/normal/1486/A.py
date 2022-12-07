mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    for _ in range(int(input())):
        N = int(input())
        A = list(map(int, input().split()))

        ok = 1
        cur = 0
        for i, a in enumerate(A):
            cur += a
            if cur < i:
                ok = 0
                break
            cur -= i
        if ok:
            print("YES")
        else:
            print("NO")


if __name__ == '__main__':
    main()