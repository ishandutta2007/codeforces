mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.buffer.readline

    for _ in range(int(input())):
        N, K, L = map(int, input().split())
        A = list(map(int, input().split()))
        A.append(-K)

        if max(A) > L:
            print("No")
            continue

        ok = 1
        k = -K-1
        for a in A:
            k += 1
            if k < 0:
                if a + K <= L:
                    k = -K-1
                if a - k > L:
                    k = -(L - a)
            else:
                if a + k > L:
                    ok = 0
                    break
                elif a + K <= L:
                    k = -K-1
        if ok:
            print("Yes")
        else:
            print("No")


if __name__ == '__main__':
    main()