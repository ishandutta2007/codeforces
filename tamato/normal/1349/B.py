mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.buffer.readline

    for _ in range(int(input())):
        N, K = map(int, input().split())
        A = list(map(int, input().split()))

        if K not in A:
            print("no")
            continue

        if N == 1:
            print("yes")
            continue

        ok = 0
        for i in range(1, N):
            if A[i] >= K:
                if A[i-1] >= K:
                    ok = 1
                    break
                if i-2 >= 0:
                    if A[i-2] >= K:
                        ok = 1
                        break
        if ok:
            print("yes")
        else:
            print("no")


if __name__ == '__main__':
    main()