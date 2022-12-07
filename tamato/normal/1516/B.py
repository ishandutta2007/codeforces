mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    for _ in range(int(input())):
        N = int(input())
        A = list(map(int, input().split()))

        S = 0
        for a in A:
            S ^= a
        if S == 0:
            print("YES")
            continue
        l = -1
        vl = 0
        for i, a in enumerate(A):
            vl ^= a
            if vl == S:
                l = i
                break
        r = N
        vr = 0
        for i in range(N-1, -1, -1):
            a = A[i]
            vr ^= a
            if vr == S:
                r = i
                break
        if l != -1 and r != N:
            if l < r:
                print("YES")
                continue
        print("NO")


if __name__ == '__main__':
    main()